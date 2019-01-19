/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var mapping = {
    ["IV"]: 4,
    ["IX"]: 9,
    ["I"]: 1,
    ["V"]: 5,
    ["XC"]: 90,
    ["XL"]: 40,
    ["X"]: 10,
    ["L"]: 50,
    ["CM"]: 900,
    ["CD"]: 400,
    ["C"]: 100,
    ["D"]: 500,
    ["M"]: 1000
  };
  var keys = Object.keys(mapping);
  var sum = 0;

  while (s.length > 0) {
      keys.forEach(key => {
          if (s.startsWith(key)) {
              sum += mapping[key];
              s = s.substring(key.length);
          }
      });
  }

  return sum;
};