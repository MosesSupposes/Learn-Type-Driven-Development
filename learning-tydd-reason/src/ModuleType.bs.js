// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var $$String = require("bs-platform/lib/js/string.js");

function make(id, name) {
  return {
          id: id,
          name: $$String.trim($$String.capitalize(name))
        };
}

var Person = {
  make: make
};

exports.Person = Person;
/* No side effect */