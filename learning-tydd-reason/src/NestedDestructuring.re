type fullName = {
  firstName: string,
  lastName: string,
};
type t = {
  name: fullName,
  id: int,
};

let jim = {
  name: {
    firstName: "jim",
    lastName: "craft",
  },
  id: 0,
};
let {name: {firstName}} = jim;
Js.log(firstName); // jim
