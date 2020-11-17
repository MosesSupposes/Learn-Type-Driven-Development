module type PersonType = {
  type t = {
    id: int,
    name: string,
  };
  let make: (int, string) => t;
};

module Person: PersonType = {
  type t = {
    id: int,
    name: string,
  };

  let massage = name => name |> String.capitalize |> String.trim;
  let make = (id, name) => {id, name: massage(name)};
};
