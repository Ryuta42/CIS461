#include "compiler.h"

int scope = 0;
ofstream out;

string nodeType[] = {
  "NODE" ,
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

void err(string message)
{ cerr << "ERROR: " << fn << ": " << message << endl;
  incErr();
}
void err(string message, int line)
{ cerr << "ERROR: " << fn << ":" << line << ": " << message << endl;
  incErr();
}
void incErr()
{ if (++numErrors >= 10)
  {   cerr << "Too many errors detected. Aborting compilation..." << endl;
      exit(-1);
  }
}
int numErrors = 0;

/* --- CTNode --- */
stack<string> CTNode::getAncestry()
{ stack<string> anc;
  CTNode* curr = this;
  while (curr->label != "-")
  { anc.push(curr->label);
    curr = curr->parent;
  }
  return anc;
}
void CTNode::print(int depth)
{ for (int i = depth; i > 0; i--)      cout << "|   ";
  cout << ext << "->" << label << " (" << vtable.size() << ")" << endl;
  for (auto &v : vtable)
  { for (int i = depth; i > 0; i--)      cout << "    ";
    cout << v.first << ": " << v.second << endl;
  }
  for (auto &m : mtable)
  { for (int i = depth; i > 0; i--)      cout << "    ";
    m.second.print();
  }
  for (auto &it : ch)           it->print(depth+1);               // recursively print ch
}

/* --- ClassTree --- */
ClassTree::ClassTree()
{ processed = false;
  root = new CTNode("Obj", "-");
  map <string, string> biv;                                       // add built in variable declarations
  map <string, CTMethod> bim;                                     // add built in method declarations
  CTMethod m = CTMethod("PRINT","Nothing");
  bim.insert(pair<string,CTMethod>("PRINT", m));
  m = CTMethod("STR","String");
  bim.insert(pair<string,CTMethod>("STR", m));
  m = CTMethod("EQUAL","Boolean");
  bim.insert(pair<string,CTMethod>("EQUAL", m));
  addVTable("Obj", &biv, &bim, 0);

  addToTree(new NClass("String", "Obj"));                         // add built in classes
  addToTree(new NClass("Int", "Obj"));
  addToTree(new NClass("Nothing", "Obj"));
  addToTree(new NClass("Boolean", "Obj"));
}
bool ClassTree::addToTree(NClass* n)
{ if (searchTree(n->label))   return false;                       // Class already defined
  CTNode* parent = searchTree(n->extends);
  if (!parent)                return false;                       // Extention not defined
  CTNode* child = new CTNode(n->label, n->extends);
  child->vtable = parent->vtable;
  child->mtable = parent->mtable;
  parent->addChild(child);
  return true;
}
string ClassTree::lca(string c1, string c2)
{ string result = "-";
  if (!processed)
  { cerr << "Classes have not yet been processed" << endl;
    return result;
  }
  CTNode *n1, *n2;
  if (c1 == "-" && c2 == "-")
    return "-";
  else if (c1 == "-" && c2 != "-" && (n2 = searchTree(c2)))
    return c2;
  else if (c2 == "-" && c1 != "-" && (n1 = searchTree(c1)))
    return c1;
  if (!(n1 = searchTree(c1)))
  { cerr << "Class '" << c1 << "' has not been defined" << endl;
    return result;
  }
  else if (!(n2 = searchTree(c2)))
  { cerr << "Class '" << c2 << "' has not been defined" << endl;
    return result;
  }
  stack<string> s1 = n1->getAncestry();
  stack<string> s2 = n2->getAncestry();
  while(s1.top() == s2.top())
  { result = s1.top();
    s1.pop();
    s2.pop();
    if (s1.empty() || s2.empty())   break;
  }
  return result;
}
bool ClassTree::checkSubclass(string sub, string super)
{ CTNode* n = searchTree(sub);
  stack<string> s = n->getAncestry();
  while(!s.empty())
  { if (s.top() == super)   return true;
    s.pop();
  }
  return false;
}
bool ClassTree::addVTable(string className, map<string,string>* vt, map<string,CTMethod>* mt, int line)
{ CTNode* c = searchTree(className);
  if (!c)     return false;

  bool success = true;
  if (className != "Obj")
  { c->vtable = c->parent->vtable;
    c->mtable = c->parent->mtable;
  }
  for (auto &v : *vt)
  { if (c->vtable.count(v.first) > 0)
    { if (checkSubclass(v.second, c->vtable[v.first]))
        c->vtable[v.first] = v.second;
      else
      { err("Improper override of variable '" + v.first + "'. '" + v.second + "' is not a subclass of '" + c->vtable[v.first] + "'", line);
        success = false;
      }
    }
    else
      c->vtable.insert(v);
  }
  for (auto &m : *mt)
  { if (c->mtable.count(m.first) > 0)
    { if (checkSubclass(m.second.type, c->mtable[m.first].type))
        c->mtable[m.first] = m.second;
      else
      { err("Improper override of method '" + m.first + "'. Return type '" + m.second.type + "' is not a subclass of '" + c->mtable[m.first].type + "'", line);
        success = false;
      }
    }
    else
      c->mtable.insert(m);
  }
  return success;
}

/* --- AST --- */
int AST::process()
{ buildClassTree();
  validateClassCalls(root);
  checkVarInit(root->ch.back());
  typeCkeck();
  //printTree();
  //printClasses();
  if (numErrors == 0)  generateCode();
  else
  { cerr << "Problem processing source file. Compilation terminated." << endl;
    return 1;
  }
  return 0;
}
bool AST::buildClassTree()
{ bool changed;
  do                                    // add class declarations to class tree
  { changed = false;
    for (auto &c : classVector)
    { if (!c->addedToTree && classTree.addToTree(c))
      { c->addedToTree = true;
        changed = true;
      }
      vtable.insert(pair<string, string>(c->label, ">class"));    // add declaration to global vtable
    }
  } while (changed);
  classTree.processed = true;
  bool valid = true;
  for (auto &c : classVector)
  { if (!c->addedToTree)
    { err("There was a problem adding class '" + c->label + "'");
      valid = false;
    }
  }
  if (valid)
    addTablesForClass("Obj");

  return classTree.isPerfect;
};
void AST::addTablesForClass(string label)
{ CTMethod args;
  Node* nt;                             // temp node p
  map<string, string> cvt;             // Class variable table p
  map<string, CTMethod> cmt;           // Class method table p
  for (auto &c : classVector)         // add member variables and methods
  { if (c->label == label)
    { nt = c->ch.front();                         // class signature
      for (auto &n3 : nt->ch.front()->ch)         // formal args
      { if (cvt.count(n3->label) == 0)
          cvt.insert(pair<string, string>(n3->label, n3->valueType));
        else
          err("Constructor labelled '" + n3->label + "' has already been defined", n3->line);
      }
      nt = c->ch.back();                          // class body
      for (auto &n3 : nt->ch.front()->ch)         // constructors
      { // CONSTRUCTOR PROCESSING
      }
      for (auto &n3 : nt->ch.back()->ch)          // methods
      { if (cmt.count(n3->label) == 0)
        { args = CTMethod(n3->label, n3->valueType);
          for (auto &a: n3->ch.front()->ch)
            args.addArg(a->label, a->valueType);
          cmt.insert(pair<string, CTMethod>(n3->label, args));
        }
        else
          err("Method labelled '" + n3->label + "' has already been defined", n3->line);
      }
      if (!(classTree.addVTable(c->label, &cvt, &cmt, c->line)))
      { err("There was a problem adding the vtable for class '" + c->label + "'");
        classTree.isPerfect = false;
      }
    }
  }
  CTNode* n = classTree.searchTree(label);
  for (auto &c : n->ch)   addTablesForClass(c->label);        // work down the class tree and add vtables
}
bool AST::verifyClass(const string& s, int line)
{ if (classTree.searchTree(s))
    return true;
  else
    err("Class '" + s + "' is undefined", line);
  return false;
}
bool AST::verifyLabel(const string& s, map<string, string>* vt, int line)
{ if ((s == ">Int_literal") || (s == ">Str_literal") || (vt->count(s) > 0))
    return true;
  else
    err("'" + s + "' has not been declared in this scope", line);
  return false;
}
void AST::addVariable(string label)
{ vtable.insert(pair<string, string>(label, "-"));
}
string AST::classVarType(string classLabel, string member, int line)
{ if (verifyClass(classLabel, line))
  { CTNode* ctn = classTree.searchTree(classLabel);
    if (ctn->vtable.count(member) > 0)
      return ctn->vtable[member];
    else
      err("'" + member + "' is not a member in class '" + ctn->label + "'", line);
  }
  return "-";
}
string AST::classMethType(string classLabel, string method, int line)
{ CTNode* ctn = classTree.searchTree(classLabel);
  if (ctn->mtable.count(method) > 0)
  { return ctn->mtable[method].type;
  }
  else
    err("'" + method + "' is not a method of class '" + ctn->label + "'", line);
  return "-";
}
bool AST::validateClassCalls(Node* n)
{ switch (n->type)
  { case NEX:
      if (CEXP(n)->subtype == NEXCLASS)
        return verifyClass(n->valueType, n->line);
    break;
    case NSTATEMENT:
      if (CSTA(n)->subtype == NSTASSIGNT)
        return verifyClass(n->valueType, n->line);
    break;
    case NEXTENDS:
    case NFORMAL_ARG:
    case NMETHOD:
      return verifyClass(n->valueType, n->line);
    break;
  }
  for (auto &c : n->ch)         // recursively check children
    if (!validateClassCalls(c))
      return false;
  return true;
}
bool AST::checkVarInit(Node* n)
{ switch (n->type)
  { case NEX:
      switch (CEXP(n)->subtype)
      { case NLEX:
          return verifyLabel(n->label, &vtable, n->line);
        break;
        case NLEXQ:
          if (vtable[n->ch.front()->label] != "-")
            return classVarType(vtable[n->ch.front()->label], n->label, n->line) != "-";
        break;
        case NEXMETH:
          return checkVarInit(n->ch.front()) && checkVarInit(n->ch.back());   // check arguments
        break;
        case NEXCLASS:
          return checkVarInit(n->ch.front());
        break;
      }
    break;
    case NSTATEMENT:
      switch (CSTA(n)->subtype)
      { case NSTASSIGN:
        case NSTASSIGNT:
          if (CASN(n)->left->subtype == NLEXQ)
            checkVarInit(CASN(n)->left);
          if (checkVarInit(CASN(n)->right) && vtable.count(CASN(n)->left->label) == 0)
            addVariable(CASN(n)->left->label);
        break;
        case NSTEX:
          return checkVarInit(n->ch.front());
        break;
      }
    break;
    case NACTUAL_ARGS:
    case NSTATEMENT_SEC:
      for (auto &c : n->ch)   checkVarInit(c);
    break;
  }

  return true;
}
bool AST::typeCkeck()
{ bool changed;
  map<string, string> oldTable;
  do {
    changed = false;
    oldTable = vtable;
    inferType(root->ch.back(), false);
    if (oldTable != vtable)
      changed = true;
  } while(changed);
  do {
    changed = false;
    oldTable = vtable;
    inferType(root->ch.back(), true);
    if (oldTable != vtable)
      changed = true;
  } while(changed);
  checkType(root->ch.back());
}
bool AST::inferType(Node* n, bool withFuncs)
{ string common = "--";
  switch (n->type)
  { case NEX:
      switch (CEXP(n)->subtype)
      { case NLEX:
          common = vtable[n->label];
          n->valueType = common;
        break;
        case NLEXQ:
          common = classVarType(vtable[n->ch.front()->label], n->label, n->line);
          n->valueType = common;
          inferType(n->ch.front(), withFuncs);
        break;
        case NEXMETH:
          if (withFuncs)
          { inferType(n->ch.front(), withFuncs);
            common = classMethType(vtable[n->ch.front()->label], n->label, n->line);
            n->valueType = common;
            for (auto &a : CMET(n)->args->ch)   inferType(a, withFuncs);
          }
        break;
        case NEXPAR:
          common = inferType(n->ch.front(), withFuncs);
          n->valueType = common;
        break;
        case NINT:
          n->valueType = "Int";
        break;
      }
    break;
    case NSTATEMENT:
      switch (CSTA(n)->subtype)
      { case NSTASSIGN:
          if (vtable.count(CASN(n)->left->label) > 0)
            CASN(n)->left->valueType = vtable[CASN(n)->left->label];
          inferType(CASN(n)->right, withFuncs);
          common = classTree.lca(CASN(n)->left->valueType, CASN(n)->right->valueType);
          CASN(n)->left->valueType = common;
          vtable[CASN(n)->left->label] = common;
          n->valueType = common;
        break;
        case NSTEX:
          inferType(n->ch.front(), withFuncs);
          n->valueType = n->ch.front()->valueType;
        break;
      }
    break;
    case NSTATEMENT_SEC:
      for (auto &c : n->ch)   inferType(c, withFuncs);
    break;
  }
}
void AST::checkType(Node* n)
{ if (n->type == NEX && n->valueType == "-")
    err("Type of '" + n->label + "' could not be inferred", n->line);
  for (auto &c : n->ch)   checkType(c);
}
void AST::generateCode()
{ out.open("output.c");

  write("#include <stdio.h>");
  write("#include <stdlib.h>\n");
  write("#include \"Builtins.h\"\n");
  write("void quackmain();\n");

  genClasses();

  write("int main(int argc, char** argv) {"); scope++;
  write("quackmain();");
  write("printf(\"--- Terminated successfully ---\\n\");");
  write("exit(0);");
  scope--; write("}");

  write("void quackmain() {"); scope++;
  genDeclarations();
  genCode(root->ch.back());
  scope--; write("}");
  out.close();
}
void AST::genClasses()
{ string c;
  for (auto &cl : vtable)
  { if (cl.second == ">class")
    { c = cl.first;
      // struct class_Obj_struct;
      // typedef struct class_Obj_struct* class_Obj;
      write("struct class_" + c + "_struct;");
      write("typedef struct class_" + c + "_struct* class_" + c + ";");

      // typedef struct obj_Obj_struct {
      //   struct class_Obj_struct *clazz;
      // } * obj_Obj;
      write("typedef struct obj_" + c + "_struct {");
      scope++;
      write("struct class_" + c + "_struct *clazz;");
      scope--;
      write("} * obj_" + c + ";");

      // struct class_Obj_struct {
      //   /* Method table */
      //   obj_Obj (*constructor) ( void );
      //   obj_String (*STRING) (obj_Obj);
      //   obj_Obj (*PRINT) (obj_Obj);
      //   obj_Boolean (*EQUALS) (obj_Obj, obj_Obj);
      // };
      write("struct class_" + c + "_struct {");
      scope++;
      write("obj_Obj (*constructor) ( void );");
      write("obj_String (*STRING) (obj_Obj);");
      write("obj_Obj (*PRINT) (obj_Obj);");
      write("obj_Boolean (*EQUALS) (obj_Obj, obj_Obj);");
      scope--;
      write("};");

      write("");
    }
  }
}
void AST::genDeclarations()
{ for (auto &n : vtable)
  { if (n.second != ">class")
      write("obj_" + n.second + " " + n.first + ";");
  }
}
string AST::genCode(Node* n)
{ switch (n->type)
  { case NEX:
      switch (CEXP(n)->subtype)
      { case NINT:
          return "int_literal(" + to_string(static_cast<NInt*>(n)->value) + ")";
        break;
        case NSTRING:
          return "str_literal(" + static_cast<NString*>(n)->value + ")";
        break;
        case NLEX:
          return n->label;
        break;
        case NLEXQ:
          return n->ch.front()->label + "." + n->label;
        break;
        case NEXMETH:
          return genCode(n->ch.front()) + "->clazz->" + n->label + "(" + ")";
        break;
        case NEXPAR:
          return "(" + genCode(n->ch.front()) + ")";
        break;
      }
    break;
    case NSTATEMENT:
      switch (CSTA(n)->subtype)
      { case NSTASSIGN:
          write(CASN(n)->left->label + " = " + genCode(CASN(n)->right) + ";");
        break;
        case NSTEX:
          write(genCode(n->ch.front()) + ";");
        break;
      }
    break;
    case NSTATEMENT_SEC:
      for (auto &c : n->ch) genCode(c);
    break;
  }
  return "-";
}
