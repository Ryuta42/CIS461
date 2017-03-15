#include "ast.h"

string memberType[] = {
    "ERROR",
    "VARIABLE",
    "METHOD"
};

string nodeType[] = {
    "ODE" ,
    "PROGRAM" ,
    "CLASS_SEC" ,
    "CLASS" ,
    "CLASS_SIG" ,
    "EXTENDS" ,
    "FORMAL_ARG_SEC" ,
    "FORMAL_ARG" ,
    "CLASS_BODY" ,
    "STATEMENT_SEC" ,
    "STATEMENT_BLOCK" ,
    "STATEMENT" ,
    "STATEMENT EXP" ,
    "STATEMENT IF" ,
    "STATEMENT WHILE" ,
    "STATEMENT ASSIGN" ,
    "STATEMENT ASSIGN TYPED" ,
    "STATEMENT RETURN" ,
    "EXPRESSION" ,
    "LEFT EXP" ,
    "LEFT EXP QUALIFIED" ,
    "RIGHT EXP" ,
    "INT" ,
    "STRING" ,
    "EXP ADD" ,
    "EXP SUBTRACT" ,
    "EXP MULTIPLY" ,
    "EXP DIVIDE" ,
    "EXP EQUALS" ,
    "EXP ATMOST" ,
    "EXP LESSTHAN" ,
    "EXP ATLEAST" ,
    "EXP GREATERTHAN" ,
    "EXP AND" ,
    "EXP OR" ,
    "EXP NOT" ,
    "EXP METHOD CALL" ,
    "EXP CLASS CONSTRUCTOR" ,
    "EXP PARENTHASES" ,
    "EXP ERROR" ,
    "ACTUAL_ARG_SEC" ,
    "ACTUAL_ARGS" ,
    "ELIF" ,
    "ELIF_BLOCK" ,
    "ELIF_BLOCKS" ,
    "ELSE" ,
    "ELSE_BLOCK" ,
    "METHOD_SEC" ,
    "METHOD" ,
    "RETURN_TYPE" ,
    "UNDEFINED TYPE"
};

void err(string message, int line)
{   cerr << "ERROR: " << fn << ":" << line << ": " << message << endl;
    incErr();
}
void incErr()
{   ++numErrors;
    //if ( >= 10)
    // {   cerr << "Too many errors detected. Aborting compilation..." << endl;
    //     exit(-1);
    // }
}
int numErrors = 0;

/* --- CTNode --- */
stack<string> CTNode::getAncestry()
{   stack<string> anc;
    CTNode* curr = this;
    while (curr->label != "-")
    {   anc.push(curr->label);
        curr = curr->parent;
    }
    return anc;
}

/* --- ClassTree --- */
bool ClassTree::addToTree(NClass* n)
{   if (searchTree(n->label))   return false;           // Class already defined
    CTNode* parent = searchTree(n->extends);
    if (!parent)                return false;           // Extention not defined
    CTNode* child = new CTNode(n->label, n->extends);
    child->vtable = parent->vtable;
    parent->addChild(child);
    return true;
}
string ClassTree::lca(string c1, string c2)
{   string result = "BOTTOM";
    if (!processed)
    {   cerr << "Classes have not yet been processed" << endl;
        return result;
    }
    CTNode *n1, *n2;
    if (!(n1 = searchTree(c1)))
    {   cerr << "Class '" << c1 << "' has not been defined" << endl;
        return result;
    }
    else if (!(n2 = searchTree(c2)))
    {   cerr << "Class '" << c2 << "' has not been defined" << endl;
        return result;
    }
    stack<string> s1 = n1->getAncestry();
    stack<string> s2 = n2->getAncestry();
    while(s1.top() == s2.top())
    {   result = s1.top();
        s1.pop();
        s2.pop();
        if (s1.empty() || s2.empty())   break;
    }
    return result;
}
bool ClassTree::checkSubclass(string sub, string super)
{   if (!processed)
    {   cerr << "Classes have not yet been processed" << endl;
        return false;
    }
    CTNode* n = searchTree(sub);
    stack<string> s = n->getAncestry();
    while(!s.empty())
    {   if (s.top() == super)   return true;
        s.pop();
    }
    return false;
}
bool ClassTree::addVTable(string className, map<string, tuple<string, MemberType> >* map)
{   CTNode* c = searchTree(className);
    if (!c)     return false;
    for (auto &it : *map)
    {   if (c->vtable.count(it.first) > 0)
        {       // TODO verify overwite is compatible class
            c->vtable[it.first] = it.second;
        }
        else
            c->vtable.insert(it);
    }
    return true;
}

/* --- AST --- */
bool AST::buildClassTree()
{   map<string, tuple<string, MemberType> >* cvt;
    Node* nt;
    bool changed;
    do
    {   changed = false;
        for (auto &c : classVector)
        {   if (!c->addedToTree)
            {   cvt = new map<string, tuple<string, MemberType> >();
                //cout << "Class: " << c->label << "   " << c->extends << endl;
                nt = c->ch.front();                         // class signature
                for (auto &n3 : nt->ch.front()->ch)         // formal args
                {   //cout << "formal arg: " << n3->label << ": " << n3->valueType << endl;
                    if (cvt->count(n3->label) == 0)
                        cvt->insert(pair<string, tuple<string, MemberType> >(n3->label, make_tuple(n3->valueType, VARIABLE)));
                    else
                        err("Constructor labelled '" + n3->label + "' has already been defined", n3->line);
                }
                nt = c->ch.back();                          // class body
                for (auto &n3 : nt->ch.front()->ch)         // constructors
                {   //cout << "constructor: " << n3->ch.front()->label << ": " << nodeType[n3->ch.front()->type] << endl;
                }
                for (auto &n3 : nt->ch.back()->ch)          // methods
                {   //cout << "method: " << n3->label << ": " << nodeType[n3->type] << endl;
                    if (cvt->count(n3->label) == 0)
                        cvt->insert(pair<string, tuple<string, MemberType> >(n3->label, make_tuple(n3->valueType, METHOD)));
                    else
                        err("Method labelled '" + n3->label + "' has already been defined", n3->line);
                }

                if (classTree.addToTree(c))
                {   c->addedToTree = true;
                    changed = true;
                }
                // for (auto &n4 : *cvt)   // print class vtable
                // {   cout << " " << n4.first << " " << n4.second << endl;
                // }
                // cout << endl;
                if (!(classTree.addVTable(c->label, cvt)))      cerr << "Problem adding vtable" << endl;
                vtable.insert(pair<string, string>(c->label, ">class"));    // add declaration to global vtable
            }
        }
    } while (changed);

    bool valid = true;
    for (auto &c : classVector)
    {   if (!c->addedToTree)
        {   cerr << "There was a problem adding class '" << c->label << "'" << endl;
            valid = false;
        }
    }
    classTree.processed = true;
    //printClasses();
    return valid;
};
bool AST::passes()
{   cout << "Class calls:" << endl;
    validateClassCalls(root);
    cout << endl;

    cout << "Variable Inits:" << endl;
    checkVarInitInClass(root->ch.front());
    checkVarInit(root);
    cout << endl;

    interpretType(root->ch.back());

    // print global vtable
    cout << "\nGlobal vtable:" << endl;
    for (auto &n : vtable)
    {   cout << n.first << " " << n.second << endl;
    }

    return true;
}
bool AST::verifyClass(const string& s, int line)
{   if (classTree.searchTree(s))
        return true;
    else
        err("Class '" + s + "' is undefined", line);
    return false;
}
bool AST::verifyLabel(const string& s, map<string, string>* vt, int line)
{   if ((s == ">int_literal") || (vt->count(s) > 0))
        return true;
    else
        err("'" + s + "' has not been declared in this scope", line);
    return false;
}
int AST::process()
{   printTree();
    if (!buildClassTree())  return 1;
    if (!passes())          return 2;
    //printClasses();

    cout << "\n--Compile completed with " << numErrors << " error(s)--" << endl;
    write();
    return 0;
}
void AST::addVariable(string label, string type)
{   vtable.insert(pair<string, string>(label, type));
    cout << "Assigning " + label + " type " + type << endl;
}
void AST::classVarLookup(string classLabel, string member)
{   CTNode* ctn = classTree.searchTree(classLabel);
    if (ctn->vtable.count(member) > 0)
    {   switch (get<1>(ctn->vtable[member]))
        {   case VARIABLE:
            break;
            case METHOD:
                err("'" + member + "' is a method of class '" + ctn->label + "', not a member variable", 0);
            break;
        }
    }
    else
        err("'" + member + "' is not a member in class '" + ctn->label + "'", 0);
}
void AST::classMethLookup(string classLabel, string method)
{   CTNode* ctn = classTree.searchTree(classLabel);
    if (ctn->vtable.count(method) > 0)
    {   switch (get<1>(ctn->vtable[method]))
        {   case METHOD:
            break;
            case VARIABLE:
                err("'" + method + "' is a member variable of class '" + ctn->label + "', not a mthod", 0);
            break;
        }
    }
    else
        err("'" + method + "' is not a method of class '" + ctn->label + "'", 0);
}
void AST::validateClassCalls(Node* n)
{   switch (n->type)
    {   case NEX:
            if (static_cast<NExpression*>(n)->subtype == NEXCLASS)
            {   cout << n->line << ":\t" << n->label << ":\t" << nodeType[static_cast<NExpression*>(n)->subtype] << endl;
                verifyClass(n->valueType, n->line);
            }
        break;
        case NSTATEMENT:
            if (static_cast<NStatement*>(n)->subtype == NSTASSIGNT)
            {   cout << n->line << ":\t" << n->valueType << ":\t" << nodeType[static_cast<NStatement*>(n)->subtype] << endl;
                verifyClass(n->valueType, n->line);
            }
        break;
        case NEXTENDS:
        case NFORMAL_ARG:
        case NMETHOD:
            cout << n->line << ":\t" << n->valueType << ":\t" << nodeType[n->type] << endl;
            verifyClass(n->valueType, n->line);
        break;
    }
    for (auto &c : n->ch)   validateClassCalls(c);
}
bool AST::checkVarInitInClass(Node* n)
{   switch (n->type)
    {   case NCLASS_SEC:
        for (auto &c: n->ch)
        {   for(auto &c2: c->ch.back()->ch.front()->ch)     // class constructor
            {   cout << "class const" << endl;
                cout << c->label + " " + c2->label << endl;
            }
            for(auto &c2: c->ch.back()->ch.back()->ch)      // class methods
            {   cout << "method definitions" << endl;
                checkVarInit(c2);
            }
        }
        break;
    }
    return true;
}
bool AST::checkVarInit(Node* n)
{   switch (n->type)
    {   case NEX:
            switch (static_cast<NExpression*>(n)->subtype)
            {   case NLEX:
                    return verifyLabel(n->label, &vtable, n->line);
                break;
                case NLEXQ:
                    cout << "qualified LEX " << n->label << endl;
                    classVarLookup(vtable[n->ch.front()->label], n->label);
                break;
                case NEXMETH:
                    cout << "method call " << n->ch.front()->label << endl;
                    cout << n->ch.front()->label << " : " << vtable[n->ch.front()->label] << endl;
                    cout << n->label << endl;
                    classMethLookup(vtable[n->ch.front()->label], n->label);

                    // check arguments
                    return checkVarInit(n->ch.back());
                break;
                case NEXCLASS:
                    //cout << "class constructor " << n->label << endl;
                    return checkVarInit(n->ch.front());
                break;
            }
        break;
        case NSTATEMENT:
            switch (static_cast<NStatement*>(n)->subtype)
            {   case NSTASSIGN:
                case NSTASSIGNT:
                    cout << "assignment to " << static_cast<NAssignment*>(n)->left->label <<
                      ": " << nodeType[static_cast<NAssignment*>(n)->left->subtype] << endl;
                    if (static_cast<NAssignment*>(n)->left->subtype != NLEX)
                        checkVarInit(static_cast<NAssignment*>(n)->left);
                    if (checkVarInit(static_cast<NAssignment*>(n)->right))
                        addVariable(static_cast<NAssignment*>(n)->left->label, static_cast<NAssignment*>(n)->right->valueType);
                break;
                case NSTEX:
                    //cout << "Expression statement: " << n->ch.front()->label << endl;
                    //cout << "----type: " << nodeType[static_cast<NExpression*>(n->ch.front())->subtype] << endl;
                    checkVarInit(n->ch.front());
                break;
            }
        break;
        case NACTUAL_ARG_SEC:
            for (auto &a : n->ch)
            {   //cout << "checking arg " << a->label << endl;
                checkVarInit(a);
            }
        break;
        case NSTATEMENT_SEC:
            cout << "statement section" << endl;
            for (auto &c : n->ch)   checkVarInit(c);
        break;
        case NPROGRAM:
            checkVarInit(n->ch.back());
        break;
    }


    return true;
}
string AST::interpretType(Node* n)
{   if (n->valueType != "-")
        return n->valueType;
    string common = "--";
    switch (n->type)
    {   case NEX:
            switch (static_cast<NExpression*>(n)->subtype)
            {   case NLEX:
                    common = vtable[n->label];
                    n->valueType = common;
                break;
                case NEXADD:
                case NEXSUB:
                case NEXMUL:
                case NEXDIV:
                    common = classTree.lca(interpretType(n->ch.front()), interpretType(n->ch.back()));
                    n->valueType = common;
                break;
            }
        break;
        case NSTATEMENT:
            switch (static_cast<NStatement*>(n)->subtype)
            {   case NSTASSIGN:
                    common = interpretType(static_cast<NAssignment*>(n)->right);
                    vtable[static_cast<NAssignment*>(n)->left->label] = common;
                break;
            }
        break;
        case NSTATEMENT_SEC:
            for (auto &c : n->ch)   interpretType(c);
        break;
    }
    return common;
}
void AST::write()
{
}
