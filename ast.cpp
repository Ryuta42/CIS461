#include "ast.h"

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
    "STATEMENT IF" ,
    "STATEMENT WHILE" ,
    "STATEMENT ASSIGN" ,
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
    "RETURN_TYPE"
};

void err(string message, int line)
{   cerr << fn << ":" << line << ": " << message << endl;
}

/* --- Node --- */
void Node::validateClassCalls(AST* ast)
{   switch (type)
    {   case NEX:
            if (static_cast<NExpression*>(this)->subtype == NEXCLASS)
            {   cout << line << ":\t" << label << ":\t" << nodeType[static_cast<NExpression*>(this)->subtype] << endl;
                if (!(ast->verifyClass(valueType, line)))
                    cerr << "ERROR" << endl;
            }
        break;
        case NEXTENDS:
        case NFORMAL_ARG:
        case NMETHOD:
            cout << line << ":\t" << valueType << ":\t" << nodeType[type] << endl;
            if (!(ast->verifyClass(valueType, line)))
                cerr << "ERROR" << endl;
        break;
    }
    for (auto &it : ch)     it->validateClassCalls(ast);
}

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
bool ClassTree::addVTable(string className, map<string,string>* map)
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
{   map<string, string>* cvt;
    bool changed;
    do
    {   changed = false;
        for (auto &c : classVector)
        {   if (!c->addedToTree)
            {   cvt = new map<string, string>();
                //cout << "Class: " << c->label << "   " << c->extends << endl;
                for (auto &n2 : c->ch)
                {   switch (n2->type)
                    {   case NCLASS_SIG:
                            for (auto &n3 : n2->ch.front()->ch)         // formal args
                            {   //cout << "formal arg: " << n3->label << ": " << n3->valueType << endl;
                                if (cvt->count(n3->label) == 0)
                                    cvt->insert(pair<string, string>(n3->label, n3->valueType));
                                else
                                    cerr << "Constructor labelled '" << n3->label << "' has already been defined" << endl;
                            }
                        break;
                        case NCLASS_BODY:
                            for (auto &n3 : n2->ch.front()->ch)         // constructors
                            {   //cout << "constructor: " << n3->ch.front()->label << ": " << nodeType[n3->ch.front()->type] << endl;
                            }
                            for (auto &n3 : n2->ch.back()->ch)          // methods
                            {   //cout << "method: " << n3->label << ": " << nodeType[n3->type] << endl;
                                if (cvt->count(n3->label) == 0)
                                    cvt->insert(pair<string, string>(n3->label, "method: " + n3->valueType));
                            }
                        break;
                    }
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
                vtable.insert(pair<string, NodeType>(c->label, NCLASS));    // add declaration to global vtable
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
bool AST::pass1()
{   cout << "Class calls:" << endl;
    root->validateClassCalls(this);
    //Class Section
    for (auto &n1 : root->ch.front()->ch)        // class
    {
    }

    // print global vtable
    cout << "\nGlobal vtable:" << endl;
    for (auto &n : vtable)
    {   cout << n.first << " " << nodeType[n.second] << endl;
    }

    return true;
}
bool AST::verify(const string& s, int line)
{   if (vtable.count(s) > 0)
        return true;
    else
        err("'" + s + "' has not been declared in this scope", line);
    return false;
}
bool AST::verifyClass(const string& s, int line)
{   if (classTree.searchTree(s))
        return true;
    else
        err("Class '" + s + "' is undefined", line);
    return false;
}
int AST::process()
{   printTree();
    cout << endl;
    if (!buildClassTree())  ;//return 1;
    if (!pass1())       return 2;

    //cout << "\n\n" << endl;
    classTree.printTree();
    return 0;
}
