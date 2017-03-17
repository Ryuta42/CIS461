#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <typeinfo>
#include <tuple>
using namespace std;

#define CEXP(n) static_cast<NExpression*>(n)
#define CSTA(n) static_cast<NStatement*>(n)
#define CASN(n) static_cast<NAssignment*>(n)

#ifndef COMPILER_H
#define COMPILER_H

enum MemberType {
  ERROR,
  VARIABLE,
  METHOD
};
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
  NSTEX,
  NSTIF,
  NSTWHILE,
  NSTASSIGN,
  NSTASSIGNT,
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
  NRETURN_TYPE,
  NUNDEFINED
};
extern string memberType[];
extern string nodeType[];
extern char* fn;
extern void err(string message, int i);
extern void incErr();
extern int numErrors;

class AST;
class CTMethod;

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
  { this->label = label;
    this->valueType = valueType;
    this->type = type;
    this->line = line;
  }
  ~Node()
  { for (auto &it: ch)     if(it) delete(it);
  }
  Node* clone()
  { Node* n = new Node(label, valueType, type, line);
    n->ch = ch;
    return n;
  }
  void addChild(Node* n)
  { ch.emplace_back(n);
  }
  void print(int depth)
  { cout << line << ":\t";
    for (int i = depth; i > 0; i--)      cout << "|   ";
    cout << label << ": " << nodeType[type] << "  (" << ch.size() << ")" << endl;
    for (auto &it : ch)           it->print(depth+1);         // recursively print ch
  }
  string cg()
  { return label;
  }
};

class NExpression : public Node{
public:
  NodeType subtype;

  NExpression() {}
  NExpression(string label, NodeType subtype, int line) : NExpression(label, "-", subtype, line) { }
  NExpression(string label, string valueType, NodeType subtype, int line) : Node(label, valueType, NEX, line)
  { this->subtype = subtype;
  }
};

class NInt : public NExpression{
public:
  int value = 0;

  NInt(int value, int line) : NExpression(">Int_literal", "Int", NINT, line)
  { this->value = value;
  }
};

class NString : public NExpression{
public:
  string value = "-";

  NString(string value, int line) : NExpression("string", "String", NSTRING, line)
  { this->value = value;
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
  { this->extends = extends;
  }
};

class NStatement : public Node{
public:
  NodeType subtype;

  NStatement(string label, NodeType subtype, int line) : NStatement(label, "-", subtype, line) {}
  NStatement(string label, string valueType, NodeType subtype, int line) : Node(label, valueType, NSTATEMENT, line)
  { this->subtype = subtype;
  }
};

class NAssignment : public NStatement{
public:
  NExpression *left, *right;

  NAssignment(string label, NExpression* left, NExpression* right, int line) : NStatement(label, "-", NSTASSIGN, line)
  { this->left = left;
    this->addChild(left);
    this->right = right;
    this->addChild(right);
  }
  NAssignment(string label, string givenType, NExpression* left, NExpression* right, int line) : NStatement(label, givenType, NSTASSIGNT, line)
  { this->left = left;
    this->addChild(left);
    this->right = right;
    this->addChild(right);
  }
  void addLeft(NExpression* n)
  { left = n;
    this->addChild(n);
  }
  void addRight(NExpression* n)
  { right = n;
    this->addChild(n);
  }
};

class CTNode{
public:
  string label;
  string ext;
  CTNode* parent;
  vector<CTNode*> ch;
  map<string, string> vtable;
  map<string, CTMethod> mtable;

  CTNode(){}
  CTNode(string label, string ext)
  { this->label = label;
    this->ext = ext;
    if (ext == "-")
      this->parent = new CTNode("-", "--");
  }
  ~CTNode()
  { for (auto &it: ch)     if(it) delete(it);
  }
  void addChild(CTNode* n)
  { ch.emplace_back(n);
    n->parent = this;
  }
  void print(int depth);
  stack<string> getAncestry();
};

class CTMethod{
public:
  string label;
  string type;
  vector< tuple<string, string> > args;

  CTMethod(){}
  CTMethod(string label, string type)
  { this->label = label;
    this->type = type;
  }
  void addArg(string name, string type)
  { args.emplace_back(make_tuple(name, type));
  }
  void print()
  { cout << label + "( ";
    for (auto &a : args)
    { cout << get<0>(a) + ":" + get<1>(a) + " ";
    }
    cout << "): " + type << endl;
  }
};

class ClassTree{
public:
  CTNode* root;
  bool processed;

  ClassTree()
  { processed = false;
    root = new CTNode("Obj", "-");
    map <string, string>* biv = new map<string, string>();     // add built in variable declarations
    map <string, CTMethod>* bim = new map<string, CTMethod>();     // add built in method declarations
    biv->insert(pair<string,string>("this", ">this"));
    CTMethod m = CTMethod("PRINT","Nothing");
    m.addArg("this", "Obj");
    bim->insert(pair<string,CTMethod>("PRINT", m));
    m = CTMethod("STR","String");
    m.addArg("this", "Obj");
    bim->insert(pair<string,CTMethod>("STR", m));
    addVTable("Obj", biv, bim);

    addToTree(new NClass("String", "Obj"));                         // add built in classes
    addToTree(new NClass("Int", "Obj"));
    addToTree(new NClass("Nothing", "Obj"));
    addToTree(new NClass("Boolean", "Obj"));
  }
  ~ClassTree()
  { delete(root);
  }
  CTNode* searchTree(string label)
  { return searchTree(root, label);
  }
  CTNode* searchTree(CTNode* curr, string label)
  { if (curr->label == label)   return curr;
    CTNode* result = NULL;
    for (auto &it : curr->ch)
      if (result = searchTree(it, label))    break;
    return result;
  }
  bool addToTree(NClass* n);
  void printTree()
  { root->print(0);
  }
  string lca(string c1, string c2);
  bool checkSubclass(string sub, string super);
  bool addVTable(string className, map<string,string>* vt, map<string,CTMethod>* mt);
};

class AST{
private:
  ClassTree classTree;
  vector<NClass*> classVector;
  Node* currentNote = root;
  map<string, string> vtable;
  vector<string> initValues;
  ofstream out;
  int scope = 0;

  bool buildClassTree();
  void classVarLookup(string classLabel, string member);
  void classMethLookup(string classLabel, string member);

public:
  Node* root;

  bool checkSyntax(int nerrors)
  { if (nerrors > 0)
      return false;
    return true;
  }
  void addClass(Node* n)
  { classVector.emplace_back(static_cast<NClass*>(n));
  }
  void printClasses()
  { cout << "\nClass Tree:" << endl;
    classTree.printTree();          // Just list all classes
  }
  void printTree()
  { root->print(0);
    cout << endl;
  }
  string lca(string c1, string c2)
  { return classTree.lca(c1, c2);
  }
  bool checkSubclass(string sub, string super)
  { return classTree.checkSubclass(sub, super);
  }
  int process();       // return 0 on success
  void addVariable(string label, string type);
  bool verifyClass(const string& s, int line);
  bool verifyLabel(const string& s, map<string, string>* vt, int line);
  void validateClassCalls(Node* n);
  bool checkVarInitInClass(Node* n);
  bool checkVarInit(Node* n);
  string interpretType(Node* n);
  void generateCode();
  void genClasses();
  void genDeclarations();
  string genCode(Node* n);
  void write(string s)
  {   out << string(scope, '\t') << s << endl;
  }
};

#endif // COMPILER_H
