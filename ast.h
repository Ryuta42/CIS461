#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <typeinfo>
using namespace std;

#ifndef AST_H
#define AST_H

enum NodeType {
    NODE,
    NPROGRAM,
    NCLASS_SEC,
    NCLASS,
    NCLASS_SIG,
    NEXTENDS,
    NFORMAL_ARG_SEC,
    NFORMAL_ARG,
    NCLASS_BODY,
    NSTATEMENT_SEC,
    NSTATEMENT_BLOCK,
    NSTATEMENT,
    NSTIF,
    NSTWHILE,
    NSTASSIGN,
    NSTRETURN,
    NEX,
    NLEX,
    NLEXQ,
    NREX,
    NINT,
    NSTRING,
    NEXADD,
    NEXSUB,
    NEXMUL,
    NEXDIV,
    NEXEQ,
    NEXMOST,
    NEXLESS,
    NEXLEAST,
    NEXGREATER,
    NEXAND,
    NEXOR,
    NEXNOT,
    NEXMETH,
    NEXCLASS,
    NEXPAR,
    NEXERR,
    NACTUAL_ARG_SEC,
    NACTUAL_ARGS,
    NELIF,
    NELIF_BLOCK,
    NELIF_BLOCKS,
    NELSE,
    NELSE_BLOCK,
    NMETHOD_SEC,
    NMETHOD,
    NRETURN_TYPE
};
extern string nodeType[];
extern char* fn;
extern void err(string message, int i);

class AST;

class Node{
public:
    vector<Node*> ch;
    int line;
    string label = "-";
    string valueType = "-";
    NodeType type = NODE;

    Node() { }
    Node(string label, NodeType type) : Node(label, "-", type, -1) { }
    Node(string label, NodeType type, int line) : Node(label, "-", type, line) { }
    Node(string label, string valueType, NodeType type, int line)
    {   this->label = label;
        this->valueType = valueType;
        this->type = type;
        this->line = line;
    }
    ~Node()
    {   for (auto &it: ch)     if(it) delete(it);
    }
    Node* clone()
    {   Node* n = new Node(label, valueType, type, line);
        n->ch = ch;
        return n;
    }
    void addChild(Node* n)
    {   ch.emplace_back(n);
    }
    void print(int depth)
    {   cout << line << ":\t";
        for (int i = depth; i > 0; i--)      cout << "|   ";
        cout << label << ": " << nodeType[type] << "  (" << ch.size() << ")" << endl;
        for (auto &it : ch)           it->print(depth+1);         // recursively print ch
    }
    void validateClassCalls(AST* ast);
};

class NExpression : public Node{
public:
    NodeType subtype;

    NExpression() {}
    NExpression(string label, NodeType subtype, int line) : NExpression(label, "-", subtype, line) { }
    NExpression(string label, string valueType, NodeType subtype, int line) : Node(label, valueType, NEX, line)
    {   this->subtype = subtype;
    }
    //string typeCheck(string type)
};

class NInt : public NExpression{
public:
    int value = 0;

    NInt(int value, int line) : NExpression("int", NINT, line)
    {   this->value = value;
        this->type = NINT;
    }
};

class NString : public NExpression{
public:
    string value = "-";

    NString(string value, int line) : NExpression("string", NSTRING, line)
    {   this->value = value;
    }
};

class NClass : public Node{
public:
    string extends;
    map<string, string> constructors;
    bool addedToTree = false;

    NClass() {}
    NClass(string label, string extends) : NClass(label, extends, -1) {}
    NClass(string label, string extends, int line) : Node(label, "class", NCLASS, line)
    {   this->extends = extends;
    }
};

class NStatement : public Node{
public:
    NodeType subtype;

    NStatement(string label, NodeType subtype, int line) : Node(label, NSTATEMENT, line)
    {   this->subtype = subtype;
    }
};

class CTNode{
public:
    string label;
    string ext;
    CTNode* parent;
    vector<CTNode*> ch;
    map<string, string> vtable;

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
        cout << ext << "->" << label << " (" << vtable.size() << ")" << endl;
        for (auto &it : vtable)
        {   for (int i = depth; i > 0; i--)      cout << "    ";
            cout << it.first << ": " << it.second << endl;
        }
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
        addToTree(new NClass("String", "Obj"));
        addToTree(new NClass("Int", "Obj"));
        addToTree(new NClass("Nothing", "Obj"));
        addToTree(new NClass("Boolean", "Obj"));
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
    bool addToTree(NClass* n);
    void printTree()
    {   root->print(0);
    }
    string lca(string c1, string c2);
    bool checkSubclass(string sub, string super);
    bool addVTable(string className, map<string,string>* map);
};

class AST{
private:
    ClassTree classTree;
    vector<NClass*> classVector;
    Node* currentNote = root;
    map<string, NodeType> vtable;
    vector<string> initValues;

    bool buildClassTree();
    bool pass1();       // validate class declarations
    bool verify(const string& s, int line);

public:
    Node* root;

    void addClass(Node* n)
    {   classVector.emplace_back(static_cast<NClass*>(n));
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
    bool verifyClass(const string& s, int line);
};

#endif // AST.H
