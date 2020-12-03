/* We use a type equation to tell the compiler that this variant type defined in this module is the same as the other variant type defined in Ch05_Variants, and crucially that its constructors are also exactly the same.

   We could have simply redefined the variant type in both modules; but variant types in Reason are nominal (that is, even the same variant type definition is considered a distinct type if it's in a different module) unless we use a type equation. In this simple example it's not critical that the compiler equates the two types, but sometimes in a Reason codebase, you'll want to bring in the variant constructors from another module for ease of access. Otherwise, you'll need to either open the other module (risky) or prefix the constructors with the modules (verbose), for example, Ch05_Variants.Cash.
      */
type person =
  Person.t = {
    id: int,
    name: string,
  };

let classifyId = id =>
  switch (id) {
  | 1
  | 2
  | 3
  | 4
  | 5 => "Low" /* (1) */
  | 6
  | 7
  | 8
  | 9
  | 10 => "Medium"
  | _ => "High"
  };

let greet1 = person =>
  switch (person.id, person.name) {
  /* (2) */
  | (_, "Dave") => "I'm sorry, Dave, I can't let you do that."
  | (1, _) => "Hello, boss."
  | (id, name) => "Hi, " ++ name ++ " with ID " ++ string_of_int(id) ++ "!"
  };

// Pattern matching with records
let greet2 = person =>
  switch (person) {
  | {name: "Dave"} => "I'm sorry, Dave, I can't let you do that." /* (3) */
  | {id: 1} => "Hello, boss."
  | {id, name} => "Hi, " ++ name ++ " with ID " ++ string_of_int(id) ++ "!"
  };

Js.log(greet2({id: 2, name: "Dave"})); // "I'm sorry, Dave, I can't let you do that."
Js.log(greet2({id: 1, name: "Boss"})); // "Hello, boss"
Js.log(greet2({id: 3, name: "Moses"})); // Hi, Moses with ID 3!
