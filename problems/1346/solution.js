/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function(arr) {
    const ar = [];
    
    for (let i = 0; i < arr.length; i++) {
        const val = arr[i];
        
        if (ar.indexOf(val * 2) !== -1) {
            return true;
        }
        
        if (val % 2 === 0 && ar.indexOf(val / 2) !== -1) {
            return true;
        }
        
        ar.push(val);
    }
    
    return false;
};