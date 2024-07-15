/**
 * @param {number} times
 * @return {string}
 */
String.prototype.replicate = function(times) {
    let ans = "";
    
    for (let i = 0; i < times; i++) {
        ans += this;
    }
    
    return ans;
}