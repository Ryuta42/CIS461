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
    {   for(auto &it: children)         delete(it);
    }
    //virtual Node* clone() = 0;
    void addChild(Node* n)
    {   children.emplace_back(n);
    }
    void print(int depth)
    {   for(int i = depth; i > 0; i--)      cout << "|   ";
        cout << label << ": " << type << "  (" << children.size() << ")" << endl;
        for (auto &it : children)           it->print(depth+1);         // recursively print children
    }
};
