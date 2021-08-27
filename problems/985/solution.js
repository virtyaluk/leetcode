/**
 * @param {number[]} A
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(A, queries) {
    let ans = [];
    
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        
        A[query[1]] += query[0];
        ans[i] = A.filter(v => v % 2 == 0).reduce((acc, cv) => acc + cv, 0);
    }
    
    return ans;
};