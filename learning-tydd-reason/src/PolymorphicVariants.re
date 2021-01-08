type onlyWomanShoe = [ | `Slingbacks | `HighHeels];
type shoe = [ onlyWomanShoe | `Moccasins | `Boots | `Sneakers | `Wingtips];

let johndoe_shoe: shoe = `Moccasins;
let janedoe_shoe: shoe = `Slingbacks;

Js.log(johndoe_shoe);
Js.log(janedoe_shoe);

let infoAboutShoe = (s: shoe): string => {
  switch (s) {
  | `Slingbacks => "Slingbacks - Specific woman shoe"
  | `HighHeels => "High Heels - Specific woman shoe"
  | `Moccasins => "Moccasins"
  | `Boots => "Boots"
  | `Sneakers => "Sneakers"
  | `Wingtips => "Wingtips"
  };
};

Js.log(infoAboutShoe(johndoe_shoe));
Js.log(infoAboutShoe(janedoe_shoe));

let infoAboutShoe = (s: shoe): string => {
  switch (s) {
  // In Rescript the followning can be rewritten as #...onlyWomanShoe
  | #onlyWomanShoe => "Woman shoe such as Slingbacks or High Heels"
  | `Moccasins => "Moccasins"
  | `Boots => "Boots"
  | `Sneakers => "Sneakers"
  | `Wingtips => "Wingtips"
  };
};

Js.log(infoAboutShoe(johndoe_shoe));
Js.log(infoAboutShoe(janedoe_shoe));
