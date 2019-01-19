/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let str = '';
    let longestStr = 0;
    
    for (let i = 0; i < s.length; i++) {
        const ch = s[i];

        if (str.indexOf(ch) === -1) {
            str += ch;
        } else {    
            str = str.substring(str.indexOf(ch) + 1) + ch;
        }
        
        if (str.length > longestStr) {
            longestStr = str.length;
        }
    }
    
    return longestStr;
};