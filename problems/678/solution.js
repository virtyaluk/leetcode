/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    const len = s.length;
    let leftBalance = 0, rightBalance = 0;
    
    for (let i = 0; i < len; i++) {
        leftBalance += s[i] === '(' || s[i] === '*' ? 1 : -1;
        rightBalance += s[len - i - 1] === ')' || s[len - i - 1] === '*' ? 1 : -1;
        
        if (leftBalance < 0 || rightBalance < 0) {
            return false;
        }
    }
    
    return true;
};