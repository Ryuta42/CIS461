#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

#ifndef AST_H
#define AST_H

enum NodeType {
    NODE ,
    NPROGRAM ,
    NCLASS_SEC ,
    NCLASS ,
    NCLASS_SIG ,
    NEXTENDS ,
    NFORMAL_ARG_SEC ,
    NFORMAL_ARG ,
    NCLASS_BODY ,
    NSTATEMENT_SEC ,
    NSTATEMENT_BLOCK ,
    NSTATEMENT ,
    NSTIF ,
    NSTWHILE ,
    NSTASSIGN ,
    NSTRETURN ,
    NLEX ,
    NLEXQ ,
    NREX ,
    NREXCC ,
    NACTUAL_ARG_SEC ,
    NACTUAL_ARGS ,
    NELIF ,
    NELIF_BLOCK ,
    NELIF_BLOCKS ,
    NELSE ,
    NELSE_BLOCK ,
    NMETHOD_SEC ,
    NMETHOD ,
    NRETURN_TYPE,
    NINT,
    NSTRING
};
extern string nodeType[];

class Node {
public:
    vector<Node*> ch;
    int line;
    string label = "-";
    NodeType type = NODE;

    Node() {}
    Node(string label, NodeType type) : Node(label, type, -1) { }
    Node(string label, NodeType type, int line)
    {   this->label = label;
        this->type = type;
        this->line = line;
    }
    ~Node()
    {   for (auto &it: ch)     if(it) delete(it);
    }
    void addChild(Node* n)
    {   ch.emplace_back(n);
    }
    void print(int depth);
};

class TypedNode : public Node{
public:
    string valueType;

    TypedNode() {}
    TypedNode(string label, string valueType, NodeType type, int line): Node::Node(label, type, line)
    {   this->valueType = valueType;
    }
};

class IntNode : public TypedNode{
public:
    int value = 0;

    IntNode(int value, int line) : TypedNode(to_string(value), "INT_LIT", NINT, line)
    {   this->value = value;
    }
};

class ClassNode : public TypedNode{
public:
    string extends;
    map<string, string> constructors;

    ClassNode() {}
    ClassNode(string label, string extends) : ClassNode(label, extends, -1) {}
    ClassNode(string label, string extends, int line) : TypedNode(label, "class", NCLASS, line)
    {   this->extends = extends;
    }
};

class CTNode{
public:
    string label;
    string ext;
    CTNode* parent;
    vector<CTNode*> ch;
    map<string, string> constructors;

    CTNode(){}
    CTNode(string label, string ext)
    {   this->label = label;
        this->ext = ext;
        if (ext == "-")
            this->parent = new CTNode("-", "--");
    }
    ~CTNode()
    {   for (auto &it: ch)     if(it) delete(it);
    }
    void addChild(CTNode* n)
    {   ch.emplace_back(n);
        n->parent = this;
    }
    void print(int depth)
    {   for (int i = depth; i > 0; i--)      cout << "|   ";
        cout << ext << "->" << label << endl;
        for (auto &it : ch)           it->print(depth+1);         // recursively print ch
    }
    stack<string> getAncestry();
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
        for (auto &it : curr->ch)
            if (result = searchTree(it, label))    break;
        return result;
    }
    bool addToTree(ClassNode* n);
    void printTree()
    {   root->print(0);
    }
    string lca(string c1, string c2);
    bool checkSubclass(string sub, string super);
};

class AST{
private:
    ClassTree classTree;
    vector<ClassNode*> classVector;
    Node* currentNote = root;
    map<string, NodeType> vtable;
    vector<string> initValues;

    bool processClasses();
    bool typeCheck();
    bool verify(const string& s);
    bool verifyClass(const string& s);

public:
    Node* root;

    void addClass(Node* n)
    {   classVector.emplace_back(static_cast<ClassNode*>(n));
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
    bool checkSubclass(string sub, string super)
    {   return classTree.checkSubclass(sub, super);
    }
    int process();       // return 0 on success
};

#endif // AST.H
