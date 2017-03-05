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
    "LEFT EXP" ,
    "LEFT EXP QUALIFIED" ,
    "RIGHT EXP" ,
    "REXP CLASS CONSTRUCTOR" ,
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
    "INT" ,
    "STRING"
};


/* --- Node --- */
void Node::print(int depth)
{   cout << line << ":\t";
    for (int i = depth; i > 0; i--)      cout << "|   ";
    cout << label << ": " << nodeType[type] << "  (" << ch.size() << ")" << endl;
    for (auto &it : ch)           it->print(depth+1);         // recursively print ch
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
bool ClassTree::addToTree(ClassNode* n)
{   if (searchTree(n->label))   return false;           // Class already defined
    CTNode* parent = searchTree(n->extends);
    if (!parent)                return false;           // Extention not defined
    parent->addChild(new CTNode(n->label, n->extends));
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
    if (!(n2 = searchTree(c2)))
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

/* --- AST --- */
bool AST::processClasses()
{   bool changed;
    do
    {   changed = false;
        for (vector<ClassNode*>::iterator it = classVector.begin(); it != classVector.end(); it++)
        {   if (classTree.addToTree(*it))
            {   classVector.erase(it);
                changed = true;
                break;
            }
        }
    } while (changed);
    if (!classVector.empty())
    {   cerr << "ERROR! Problem with class hierarchy" << endl;
        cerr << "There was a problem adding the following classes:" << endl;
        for (auto &it : classVector)
            cerr << it->line << ": " << it->label << " (extends " << it->extends << ")" << endl;
        return false;
    }
    classTree.processed = true;
    //printClasses();
    return true;
};
bool AST::typeCheck()
{   map<string, string>* cvt;
    Node* nt;

    // Class Section
    for (auto &n1 : root->ch.front()->ch)        // class
    {   cvt = new map<string, string>();
        cout << "Class: " << n1->label << "   " << static_cast<ClassNode*>(n1)->extends << endl;
        for (auto &n2 : n1->ch)
        {   switch (n2->type)
            {
                case NCLASS_SIG:
                    for (auto &n3 : n2->ch.front()->ch)         // formal args
                    {
                        cout << "formal arg: " << n3->label << ": " << static_cast<TypedNode*>(n3)->valueType << endl;
                        if (cvt->count(n3->label) == 0)
                            cvt->insert(pair<string, string>(n3->label, static_cast<TypedNode*>(n3)->valueType));
                        else
                            cerr << "Constructor labelled '" << n3->label << "' has already been defined" << endl;
                    }
                break;
                case NCLASS_BODY:
                    for (auto &n3 : n2->ch.front()->ch)         // constructors
                    {   cout << "constructor: " << n3->ch.front()->label << ": " << nodeType[n3->ch.front()->type] << endl;
                    }
                    for (auto &n3 : n2->ch.back()->ch)          // methods
                    {   cout << "method: " << n3->label << ": " << nodeType[n3->type] << endl;
                    }
                break;
            }
        }
        for (auto &n1 : *cvt)
        {   cout << " " << n1.first << " " << n1.second << endl;
        }

        vtable.insert(pair<string, NodeType>(n1->label, NCLASS));
        cout << endl;
    }

    // Statement Section
    for (auto &n1 : root->ch.back()->ch)        // for each class
    {   switch (n1->type)
        {   case NSTASSIGN:
                if (vtable.count(n1->ch.front()->label) == 0)
                    vtable.insert(pair<string, NodeType>(n1->ch.front()->label, n1->type));
                else
                {  // cerr << n1->line << ": Conflicting declarations of label '" << n1->ch.front()->label << "'" << endl;
                }

                nt = n1->ch.back();
                switch (nt->type)
                {   case NREXCC:
                        if (verifyClass(nt->label))     // validate class consttructor


                    break;
                }
            break;
            case NSTIF:
            break;
            case NSTWHILE:
            break;
            case NSTRETURN:
            break;
            case NSTATEMENT:
                if (verify(n1->ch.front()->ch.front()->ch.front()->label))
                {   // process method

                }
            break;
            default:
            break;
        }
    }

    // print global vtable
    cout << "\nGlobal vtable:" << endl;
    for (auto &n : vtable)
    {   cout << n.first << " " << nodeType[n.second] << endl;
    }

    return true;
};
bool AST::verify(const string& s)
{   if (vtable.count(s) > 0)
        return true;
    else
        cerr << "ERROR: '" << s << "' has not been declared in this scope" << endl;
    return false;
}
bool AST::verifyClass(const string& s)
{   if (vtable.count(s) > 0)
        return true;
    else
        cerr << "ERROR: Class '" << s << "' is undefined" << endl;
    return false;
}
int AST::process()
{   //printTree();
    cout << endl;
    if (!processClasses())  return 1;
    if (!typeCheck())       return 2;
    return 0;
}
