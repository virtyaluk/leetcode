/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var reverse = Number(Math.abs(x).toString().split('').reverse().join(''));
    reverse = x > 0 ? reverse : reverse * -1;
    
    return reverse < Math.pow(2, 31) -1 && reverse > -Math.pow(2, 31) ? reverse : 0;
};