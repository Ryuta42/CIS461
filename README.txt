Miles Chew
CIS 461 Compiler Project
Winter 2017

--Things that do work--
> Lexer and parser both work completely. An AST is built based off the specified grammar.

> A class hierarchy tree is built based on "extends" calls. The tree is rooted at "Obj" and includes the built-in types. Circular class declarations are automatically rejected through this, as are classes that extend an undefined class.

> Classes can be declared in any order. If C1 extends Obj and C2 extends C1, it doesn't matter which order C1 and C2 are declared in.

> Method signatures are passed to subclasses. If class C defines a method m():Int, subclasses of C will also have m():Int.

> Variable overrides are verified to be a subclass of the overridden variable's type. If class Pt has member variables x:Int and y:Int, a subclass of Pt can only redefine x and y if their new types are subclasses of Int.

> Method overrides are verified to return a subclass of the overridden method's return type. If a class redefines the built-in STR():String method, it must return a subclass of String.

> Variables used are verified as being declared beforehand. A variable cannot be used without it first being assigned a value.

> Any type that is mentioned is verified to have been a declared class or a built-in type. "a = Square(2);" is not allowed if the class Square is not defined.

> Type Inference. The types of variables are inferred based on the assignments to them. Types are first inferred without method calls in mind, then with.

> After type inferencing, qualified expressions are verified to exist. If there is a statement "x.double();" and x is inferred to be of type T, then we make sure class T has a method double() defined. This is the same with member variables. (Almost got to dynamic dispatch)

> Error messages are printed, usually with a line number, specifying a problem with the source code. If there are any errors, code is not generated. If there are 10 errors found, compilation stops.

> The beginning of code generation: Variables are declared with their inferred classes. Int literals and string literals are assigned properly.


--Things that Don't Work--
> Built-in methods don't work properly. There's no PLUS() method built-in.
> Dynamic dispatch.
> Variable Initialization checks and type checking on class declarations are skipped because I didn't know how to treat "this".
> Custom class code generation.
> The generated output file only works when using int and string literals.
