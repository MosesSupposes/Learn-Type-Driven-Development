// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

function tryFind(needle, haystack) {
  var currHaystack = haystack;
  var stop = false;
  var currItem;
  while(!stop) {
    var match = currHaystack;
    if (match) {
      var item = match.hd;
      if (Curry._1(needle, item)) {
        stop = true;
        currItem = Caml_option.some(item);
      } else {
        currHaystack = match.tl;
      }
    } else {
      stop = true;
    }
  };
  return currItem;
}

function tryFindRec(needle, _haystack) {
  while(true) {
    var haystack = _haystack;
    if (!haystack) {
      return ;
    }
    var item = haystack.hd;
    if (Curry._1(needle, item)) {
      return Caml_option.some(item);
    }
    _haystack = haystack.tl;
    continue ;
  };
}

console.log(tryFind((function (item) {
            return item === 2;
          }), {
          hd: 1,
          tl: {
            hd: 2,
            tl: {
              hd: 3,
              tl: {
                hd: 4,
                tl: {
                  hd: 5,
                  tl: /* [] */0
                }
              }
            }
          }
        }));

console.log(tryFindRec((function (item) {
            return item === 2;
          }), {
          hd: 1,
          tl: {
            hd: 2,
            tl: {
              hd: 3,
              tl: {
                hd: 4,
                tl: {
                  hd: 5,
                  tl: /* [] */0
                }
              }
            }
          }
        }));

exports.tryFind = tryFind;
exports.tryFindRec = tryFindRec;
/*  Not a pure module */