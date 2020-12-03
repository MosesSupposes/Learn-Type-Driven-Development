// The `_as _;` syntax gets rid of a compiler warning saying that `this` is unused.
let bob = {as _; pub id = 1; pub name = "Bob"}; /* (1), (2) */

let greet =
    (
      person: {
        ..
        id: int,
        name: string,
      },
    ) =>
  "Hello, " ++ person#name ++ " with ID " ++ string_of_int(person#id); /* (3) */

let jim = {
  pub id = 2;
  pub name = "Jim";
  pub sayHi = "Hi, my name is " ++ this#name /* (4) */
};

Js.log(greet(jim));
Js.log(greet({as _; pub id = 3; pub name = "Jack"}));
