#include "compiler.h"

int scope = 0;
ofstream out;

string memberType[] = {
  "ERROR",
  "VARIABLE",
  "METHOD"
};

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
  "RETURN_TYPE" ,
  "UNDEFINED TYPE"
};

void err(string message, int line)
{ cerr << "ERROR: " << fn << ":" << line << ": " << message << endl;
  incErr();
}
void incErr()
{ ++numErrors;
  //if ( >= 10)
  // {   cerr << "Too many errors detected. Aborting compilation..." << endl;
  //     exit(-1);
  // }
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
  for (auto &it : ch)           it->print(depth+1);         // recursively print ch
}

/* --- ClassTree --- */
bool ClassTree::addToTree(NClass* n)
{ if (searchTree(n->label))   return false;           // Class already defined
  CTNode* parent = searchTree(n->extends);
  if (!parent)                return false;           // Extention not defined
  CTNode* child = new CTNode(n->label, n->extends);
  child->vtable = parent->vtable;
  child->mtable = parent->mtable;
  parent->addChild(child);
  return true;
}
string ClassTree::lca(string c1, string c2)
{ string result = "BOTTOM";
  if (!processed)
  { cerr << "Classes have not yet been processed" << endl;
    return result;
  }
  CTNode *n1, *n2;
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
{ if (!processed)
  { cerr << "Classes have not yet been processed" << endl;
    return false;
  }
  CTNode* n = searchTree(sub);
  stack<string> s = n->getAncestry();
  while(!s.empty())
  { if (s.top() == super)   return true;
    s.pop();
  }
  return false;
}
bool ClassTree::addVTable(string className, map<string,string>* vt, map<string,CTMethod>* mt)
{ CTNode* c = searchTree(className);
  if (!c)     return false;
  for (auto &v : *vt)
  { if (c->vtable.count(v.first) > 0)
    {       // TODO verify overwite is compatible class
      c->vtable[v.first] = v.second;
    }
    else
      c->vtable.insert(v);
  }
  for (auto &m : *mt)
  { if (c->mtable.count(m.first) > 0)
    {       // TODO verify overwite is compatible class
      cout << "Override" << endl;
      //c->vtable[v.first] = v.second;
    }
    else
      c->mtable.insert(m);
  }
  return true;
}

/* --- AST --- */
bool AST::buildClassTree()
{ map<string, string>* cvt;             // Class variable table p
  map<string, CTMethod>* cmt;           // Class method table p
  vector< tuple<string, string> > mav;  // method argument vector
  CTMethod args;
  Node* nt;                             // temp node p
  bool changed;
  do
  { changed = false;
    for (auto &c : classVector)
    { if (!c->addedToTree)
      { cvt = new map<string, string>();
        cmt = new map<string, CTMethod>();
        nt = c->ch.front();                         // class signature
        for (auto &n3 : nt->ch.front()->ch)         // formal args
        { if (cvt->count(n3->label) == 0)
            cvt->insert(pair<string, string>(n3->label, n3->valueType));
          else
            err("Constructor labelled '" + n3->label + "' has already been defined", n3->line);
        }
        nt = c->ch.back();                          // class body
        for (auto &n3 : nt->ch.front()->ch)         // constructors
        { //cout << "constructor: " << n3->ch.front()->label << ": " << nodeType[n3->ch.front()->type] << endl;
        }
        for (auto &n3 : nt->ch.back()->ch)          // methods
        { //cout << "method: " << n3->label << ": " << nodeType[n3->type] << endl;
          if (cmt->count(n3->label) == 0)
          { cout << "method " << n3->label << endl;

            args = CTMethod(n3->label, n3->valueType);
            args.addArg("this", ">this");
            for (auto &a: n3->ch.front()->ch)
              args.addArg(a->label, a->valueType);
            cmt->insert(pair<string, CTMethod>(n3->label, args));
          }
          else
            err("Method labelled '" + n3->label + "' has already been defined", n3->line);
        }

        if (classTree.addToTree(c))
        { c->addedToTree = true;
          changed = true;
        }
        // for (auto &it : *cvt)   // print class vtable
        // {   cout << " " + it.first + " " + get<0>(it.second) + " " + memberType[get<1>(it.second)] << endl;
        // }
        // cout << endl;
        if (!(classTree.addVTable(c->label, cvt, cmt)))      cerr << "Problem adding vtable" << endl;
        vtable.insert(pair<string, string>(c->label, ">class"));    // add declaration to global vtable
      }
    }
  } while (changed);

  bool valid = true;
  for (auto &c : classVector)
  { if (!c->addedToTree)
    { cerr << "There was a problem adding class '" << c->label << "'" << endl;
        valid = false;
    }
  }
  classTree.processed = true;
  //printClasses();
  return valid;
};
bool AST::verifyClass(const string& s, int line)
{ if (classTree.searchTree(s))
    return true;
  else
    err("Class '" + s + "' is undefined", line);
  return false;
}
bool AST::verifyLabel(const string& s, map<string, string>* vt, int line)
{ if ((s == ">int_literal") || (vt->count(s) > 0))
    return true;
  else
    err("'" + s + "' has not been declared in this scope", line);
  return false;
}
int AST::process()
{ //printTree();
  if (!buildClassTree())  return 1;
  printClasses();
  validateClassCalls(root);

  cout << "Variable Inits:" << endl;
  checkVarInitInClass(root->ch.front());
  checkVarInit(root->ch.back());
  cout << endl;

  cout << "\nGlobal vtable:" << endl;
  for (auto &n : vtable)
  { cout << n.first << " " << n.second << endl;
    if (n.second != ">class")
        write("obj_" + n.second + " " + n.first + ";");
  }
  cout << endl;

  cout << "Interpreting types..." << endl;
  interpretType(root->ch.back());
  cout << endl;

  generateCode();

  cout << "\n--Compile completed with " << numErrors << " error(s)--" << endl;
  return 0;
}
void AST::addVariable(string label, string type)
{ vtable.insert(pair<string, string>(label, type));
  cout << "Assigning " + label + " type " + type << endl;
}
void AST::classVarLookup(string classLabel, string member)
{ CTNode* ctn = classTree.searchTree(classLabel);
  if (ctn->vtable.count(member) > 0)
  {

  }
  else
    err("'" + member + "' is not a member in class '" + ctn->label + "'", 0);
}
void AST::classMethLookup(string classLabel, string method)
{ CTNode* ctn = classTree.searchTree(classLabel);
  if (ctn->mtable.count(method) > 0)
  {
  }
  else
    err("'" + method + "' is not a method of class '" + ctn->label + "'", 0);
}
void AST::validateClassCalls(Node* n)
{ switch (n->type)
  { case NEX:
      if (CEXP(n)->subtype == NEXCLASS)
        verifyClass(n->valueType, n->line);
    break;
    case NSTATEMENT:
      if (CSTA(n)->subtype == NSTASSIGNT)
        verifyClass(n->valueType, n->line);
    break;
    case NEXTENDS:
    case NFORMAL_ARG:
    case NMETHOD:
      verifyClass(n->valueType, n->line);
    break;
  }
  for (auto &c : n->ch)   validateClassCalls(c);
}
bool AST::checkVarInitInClass(Node* n)
{ switch (n->type)
  { case NCLASS_SEC:
    for (auto &c: n->ch)
    { for(auto &c2: c->ch.back()->ch.front()->ch)     // class constructor
      { cout << "class const" << endl;
        cout << c->label + " " + c2->label << endl;
      }
      for(auto &c2: c->ch.back()->ch.back()->ch)      // class methods
      { cout << "method definitions" << endl;
        checkVarInit(c2);
      }
    }
    break;
  }
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
          cout << "qualified LEX " << n->label << endl;
          classVarLookup(vtable[n->ch.front()->label], n->label);
        break;
        case NEXMETH:
          // check arguments
          checkVarInit(n->ch.back());
        break;
        case NEXCLASS:
          //cout << "class constructor " << n->label << endl;
          return checkVarInit(n->ch.front());
        break;
      }
    break;
    case NSTATEMENT:
      switch (CSTA(n)->subtype)
      { case NSTASSIGN:
        case NSTASSIGNT:
          cout << "assignment to " << CASN(n)->left->label << ": " << nodeType[CASN(n)->left->subtype] << endl;
          if (CASN(n)->left->subtype != NLEX)
            checkVarInit(CASN(n)->left);
          if (checkVarInit(CASN(n)->right))
            addVariable(CASN(n)->left->label, CASN(n)->right->valueType);
        break;
        case NSTEX:
          //cout << "Expression statement: " << n->ch.front()->label << endl;
          //cout << "----type: " << nodeType[static_cast<NExpression*>(n->ch.front())->subtype] << endl;
          checkVarInit(n->ch.front());
        break;
      }
    break;
    case NACTUAL_ARG_SEC:
      for (auto &a : n->ch)
      { //cout << "checking arg " << a->label << endl;
        checkVarInit(a);
      }
    break;
    case NSTATEMENT_SEC:
      cout << "statement section" << endl;
      for (auto &c : n->ch)   checkVarInit(c);
    break;
  }

  return true;
}
string AST::interpretType(Node* n)
{ if (n->valueType != "-")
    return n->valueType;
  string common = "--";
  switch (n->type)
  { case NEX:
      switch (CEXP(n)->subtype)
      { case NLEX:
          common = vtable[n->label];
          n->valueType = common;
        break;
        case NEXMETH:
          cout << "method call " << n->ch.front()->label << endl;
          cout << n->ch.front()->label << " : " << vtable[n->ch.front()->label] << endl;
          cout << n->label << endl;
          classMethLookup(vtable[n->ch.front()->label], n->label);
        break;
        case NEXADD:
        case NEXSUB:
        case NEXMUL:
        case NEXDIV:
          common = classTree.lca(interpretType(n->ch.front()), interpretType(n->ch.back()));
          n->valueType = common;
        break;
        case NEXPAR:
          n->valueType = interpretType(n->ch.front());
        break;
      }
    break;
    case NSTATEMENT:
      switch (CSTA(n)->subtype)
      { case NSTASSIGN:
          common = interpretType(CASN(n)->right);
          vtable[CASN(n)->left->label] = common;
        break;
      }
    break;
    case NSTATEMENT_SEC:
      for (auto &c : n->ch)   interpretType(c);
    break;
  }
  return common;
}
void AST::generateCode()
{ out.open("output.c");
  write("#include <stdio.h>");
  write("#include <stdlib.h>\n");
  write("#include \"Builtins.h\"\n");
  write("void quackmain();\n");
  write("int main(int argc, char** argv) {"); scope++;
  write("quackmain();");
  write("printf(\"--- Terminated successfully ---\\n\");");
  write("exit(0);");
  scope--; write("}");

  genClasses();

  write("void quackmain() {"); scope++;
  genDeclarations();
  genCode(root->ch.back());
  write("c->clazz->PRINT((obj_Obj) c);");
  scope--; write("}");
  out.close();
}
void AST::genClasses()
{

}
void AST::genDeclarations()
{ // print global vtable
  cout << "\nGlobal vtable:" << endl;
  for (auto &n : vtable)
  { cout << n.first << " " << n.second << endl;
    if (n.second != ">class")
      write("obj_" + n.second + " " + n.first + ";");
  }
}
string AST::genCode(Node* n)
{
/*
	WRITE("z->clazz->PRINT((obj_Obj) z);");
	WRITE("obj_String newline_label = str_literal(\"\\n===\\n\");");
	WRITE("newline_label->clazz->PRINT(newline_label);");
*/
  switch (n->type)
  { case NEX:
      switch (CEXP(n)->subtype)
      { case NINT:
          return "int_literal(" + to_string(static_cast<NInt*>(n)->value) + ")";
        break;
        case NEXADD:
          //return genCode(n->ch.front()) + " + " + genCode(n->ch.back());
          return genCode(n->ch.front()) + "->clazz->PLUS(" + genCode(n->ch.front()) + "," + genCode(n->ch.back()) + ")";
        break;
        case NLEX:
          return n->label;
        break;
        case NEXMETH:
          cout << "method call " + n->label << endl;
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
          cout << "expression statement " + n->label << endl;
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
