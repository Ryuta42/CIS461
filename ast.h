#include <iostream>
#include <vector>
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

class IntNode : public Node{
public:
    int value = 0;

    IntNode(int value, string type) : Node::Node("INT_LIT", type)
    {   this->value = value;
    }
};

class ClassNode : public Node{
public:
    string extends;

    ClassNode() {}
    ClassNode(string label, string extends) : Node(label, "class")
    {   this->extends = extends;
    }
};

class CTNode{
public:
    string label;
    string ext;
    vector<CTNode*> children;

    CTNode(){}
    CTNode(string label, string ext)
    {   this->label = label;
        this->ext = ext;
    }
    ~CTNode()
    {   for (auto &it: children)     if(it) delete(it);
    }
    void addChild(CTNode* n)
    {   children.emplace_back(n);
    }
    void print(int depth)
    {   for (int i = depth; i > 0; i--)      cout << "|   ";
        cout << ext << "->" << label << endl;
        for (auto &it : children)           it->print(depth+1);         // recursively print children
    }
};

class ClassTree{
public:
    CTNode* root;

    ClassTree()
    {   root = new CTNode("Obj", "-");
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
};

class AST{
public:
    Node* root;
    ClassTree classTree;
    vector<ClassNode*> classVector;

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
        //printClasses();
        cout << "Class hierarchy is well formed!" << endl;
        return true;
    }
    void printClasses()
    {   cout << "\nClass Tree:" << endl;
        classTree.printTree();          // Just list all classes
    }
    void printTree()
    {   root->print(0);
    }
};
