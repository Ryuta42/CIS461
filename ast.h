#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Node {
public:
    vector<Node*> children;
    string label = "-";
    string type = "Node";

    Node() {}
    Node(string label, string type)
    {   this->label = label;
        this->type = type;
    }
    ~Node()
    {   for (auto &it: children)     if(it) delete(it);
    }
    //virtual Node* clone() = 0;
    void addChild(Node* n)
    {   children.emplace_back(n);
    }
    void print(int depth)
    {   for (int i = depth; i > 0; i--)      cout << "|   ";
        cout << label << ": " << type << "  (" << children.size() << ")" << endl;
        for (auto &it : children)           it->print(depth+1);         // recursively print children
    }
};

class TypedNode : public Node{
public:
    string valueType;

    TypedNode() {}
    TypedNode(string label, string valueType, string type): Node::Node(label, type)
    {   this->valueType = valueType;
    }
};

class IntNode : public TypedNode{
public:
    int value = 0;

    IntNode(int value, string type) : TypedNode::TypedNode(to_string(value), type, "INT_LIT")
    {   this->value = value;
    }
};

class ClassNode : public Node{
public:
    string extends;
    map<string, string> constructors;

    ClassNode() {}
    ClassNode(string label, string extends) : Node(label, "class")
    {   this->extends = extends;
    }
};

class MethodListNode : public Node{
public:
    vector<Node*> methodVector;


};

class CTNode{
public:
    string label;
    string ext;
    CTNode* parent;
    vector<CTNode*> children;
    //map<string, string> constructors;

    CTNode(){}
    CTNode(string label, string ext)
    {   this->label = label;
        this->ext = ext;
        if (ext == "-")
            this->parent = new CTNode("-", "--");
    }
    /*
    CTNode(string label, string ext, map<string, string> constructors)
    {   this->label = label;
        this->ext = ext;
        this->constructors = constructors;
    }
    */
    ~CTNode()
    {   for (auto &it: children)     if(it) delete(it);
    }
    void addChild(CTNode* n)
    {   children.emplace_back(n);
        n->parent = this;
    }
    void print(int depth)
    {   for (int i = depth; i > 0; i--)      cout << "|   ";
        cout << ext << "->" << label << endl;
        //for (auto &it : constructors)
        //    cout << it.first << ": " << it.second << endl;
        for (auto &it : children)           it->print(depth+1);         // recursively print children
    }
    stack<string> getAncestry()
    {   stack<string> anc;
        CTNode* curr = this;
        while (curr->label != "-")
        {   anc.push(curr->label);
            curr = curr->parent;
        }
        return anc;
    }
};

class ClassTree{
public:
    CTNode* root;
    bool processed;

    ClassTree()
    {   processed = false;
        root = new CTNode("Obj", "-");
        addToTree(new ClassNode("String", "Obj"));
        addToTree(new ClassNode("Int", "Obj"));
        addToTree(new ClassNode("Nothing", "Obj"));
        addToTree(new ClassNode("Boolean", "Obj"));

        addToTree(new ClassNode("Even", "Int"));
        addToTree(new ClassNode("PerfectSquare", "Even"));
        addToTree(new ClassNode("Odd", "Int"));
        addToTree(new ClassNode("Prime", "Odd"));
        addToTree(new ClassNode("CoolPrime", "Prime"));
    }
    ~ClassTree()
    {   delete(root);
    }
    CTNode* searchTree(string label)
    {   return searchTree(root, label);
    }
    CTNode* searchTree(CTNode* curr, string label)
    {   if (curr->label == label)   return curr;
        CTNode* result = NULL;
        for (auto &it : curr->children)
            if (result = searchTree(it, label))    break;
        return result;
    }
    bool addToTree(ClassNode* n)
    {   if (searchTree(n->label))   return false;           // Class already defined
        CTNode* parent = searchTree(n->extends);
        if (!parent)                return false;           // Extention not defined
        parent->addChild(new CTNode(n->label, n->extends));
        return true;
    }
    void printTree()
    {   root->print(0);
    }
    string lca(string c1, string c2)
    {   string result = "BOTTOM";
        if (!processed)
        {   cerr << "Classes have not yet processed" << endl;
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
    bool isSubclass(string sub, string super)
    {
        return false;
    }
};

class AST{
private:
    ClassTree classTree;
    vector<ClassNode*> classVector;

public:
    Node* root;

    void addClass(Node* n)
    {   classVector.emplace_back(static_cast<ClassNode*>(n));
    }
    bool processClasses()
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
        {   cout << "ERROR! Problem with class hierarchy" << endl;
            cout << "There was a problem adding the following classes:" << endl;
            for (auto &it : classVector)
                cout << it->label << " (extends " << it->extends << ")" << endl;
            return false;
        }
        classTree.processed = true;
        printClasses();
        return true;
    }
    void printClasses()
    {   cout << "\nClass Tree:" << endl;
        classTree.printTree();          // Just list all classes
    }
    void printTree()
    {   root->print(0);
    }
    string lca(string c1, string c2)
    {   return classTree.lca(c1, c2);
    }
};
