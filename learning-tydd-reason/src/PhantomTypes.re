/* src/Ch06/Ch06_PhantomTypes.re */

module Sql: {
  type column = string; /* (1) */
  type table = string;
  type t('a); /* (2) */

  let select: list(column) => t([ | `select]); /* (3) */
  let from: (table, t([ | `select])) => t([ | `ok]);
  let print: t([ | `ok]) => string;
} = {
  type column = string;
  type table = string;
  type t('a) = string;

  let select = columns => {
    /* (4) */
    let commalist = String.concat(", ", columns);
    {j|select $commalist|j};
  };

  let from = (table, t) => {j|$t from $table|j};
  let print = t => t; /* (5) */
};

let sql = Sql.(select(["name"]) |> from("employees") |> print); /* (6) */
Js.log(sql);

/*
 1. We alias a couple of types to serve as documentation.
 2. This is the type with the phantom type parameter; to the module consumer, it looks like a normal parameterized type. Internally, it doesn't contain, or otherwise use, any values of its parameter type.
 3. This function is the entry point into the build: it takes a column list and returns a partially constructed SQL statement. We can't do anything with this returned value except feed it into the next function, from. Notice that the type parameters are literally the types of polymorphic variants named appropriately; they just act as tags.
 4.The implementations of select and from are very simple: they just build normal strings in the form of syntactically valid SQL statements. The most interesting thing about them is that their types are enforced to take parameters such that they can only be called in a particular order: select, from, print.
 5.The print function is strikingly simple in that it just returns the built string. We can examine that and then pass it into an SQL engine to run.
 6.We build a syntactically valid SQL statement by calling the functions in the right order, enforced by the type system, and we then output them to the terminal. Note that the |> operator is called pipe-forward, and it's used to feed the output of one function as the input of the next one. We'll cover common operators in the next chapter.
 */
