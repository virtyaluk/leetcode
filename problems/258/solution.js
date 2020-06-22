/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return num < 10 ? num : num % 9 + (num % 9 == 0 ? 9 : 0);
};