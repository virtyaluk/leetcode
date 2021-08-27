/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    var transposed = [];
    
    for (var i = 0; i < A.length; i++) {
        for (var j = 0; j < A[i].length; j++) {
            if (!Array.isArray(transposed[j])) {
                transposed[j] = [];
            }
            
            transposed[j][i] = A[i][j];
        }
    }
    
    return transposed;
};