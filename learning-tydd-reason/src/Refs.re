/* src/Ch06/Ch06_Ref.re */
// Imperative version
let tryFind = (needle, haystack) => {
  let currHaystack = ref(haystack);
  let stop = ref(false);
  let currItem = ref(None);

  while (! stop^) {
    /* (1) */
    switch (currHaystack^) {
    /* (2) */
    | [item, ..._items] when needle(item) =>
      /* (3) */
      stop := true;
      currItem := Some(item);
    | [_item, ...items] => currHaystack := items /* (4) */
    | [] => stop := true /* (5) */
    };
  };

  currItem^; /* (6) */
};

// Recursive, declarative version
let rec tryFindRec = (needle, haystack) => {
  switch (haystack) {
  | [] => None
  | [item, ..._items] when needle(item) => Some(item)
  | [_item, ...items] => tryFindRec(needle, items)
  };
};

Js.log(tryFind(item => item === 2, [1, 2, 3, 4, 5]));
Js.log(tryFindRec(item => item === 2, [1, 2, 3, 4, 5]));
