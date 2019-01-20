const pairs = {
    '(': ')',
    ')': '(',
    '[': ']',
    ']': '[',
    '{': '}',
    '}': '{'
};
const open = ['(', '[', '{'];

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (!s) {
        return true;
    }
    
    if (s.length < 2 || s.length % 2 !== 0) {
        return false;
    }
    
    const ar = [];
    
    for (let i = 0; i < s.length; i++) {
        const ch = s[i];
        
        if (open.indexOf(ch) !== -1) {
            ar.push(ch);
            continue;
        }
        
        if (pairs[ch] != ar.pop()) {
            return false;
        }
    }
    
    return !ar.length;
};