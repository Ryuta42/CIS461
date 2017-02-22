#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#ifndef AST_H
#define AST_H

class Node{
public:
    string label;
    string type;
    vector<shared_ptr<Node>> children;

    Node(){}
    Node(string label);
    Node(string type, string label);
    void addChild(shared_ptr<Node> child);
    virtual void print(int depth);
};

class ClassNode : public Node{
public:
    string extends;
    map<string, string> vtable;

    ClassNode();
    ClassNode(string extends);
    ClassNode(string extends, string label);
    void print(int depth);
};

class CTNode{
public:
    string label;
    string extends;
    vector<shared_ptr<CTNode>> children;

    CTNode(){}
    CTNode(string label, string extends);
    void addChild(shared_ptr<CTNode> n);
    void print(int depth);
};

class ClassTree{
public:
    shared_ptr<CTNode> root;

    ClassTree();
    bool addToTree(shared_ptr<ClassNode> n);
    bool addToTree(shared_ptr<CTNode> n);      // returns true on success
    bool searchTree(shared_ptr<CTNode> node, string label);      // search for node in tree with given label
    void printTree();
};

class AST{
public:
    shared_ptr<Node> root;
    stack<shared_ptr<Node>> nodeStack;
    stack<shared_ptr<int>> counterStack;
    vector<shared_ptr<ClassNode>> classVector;
    //ClassTree classTree;

    AST();
    void push(shared_ptr<Node> n);
    void pop();
    shared_ptr<Node> top();
    void add(shared_ptr<Node> n);
    void addClass(shared_ptr<Node> n);
    void pushLayer();
    void popLayer(shared_ptr<Node> n);
    void printTree();
    bool checkClasses();
};

#endif // AST_H
