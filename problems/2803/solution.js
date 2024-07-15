/**
 * @param {number} n
 * @yields {number}
 */
function* factorial(n) {
    if (n === 0) {
        yield 1;
    }
    
    let ans = 1;
    
    for (let i = 1; i <= n; i++) {
        ans *= i;
        
        yield ans;
    }
};

/**
 * const gen = factorial(2);
 * gen.next().value; // 1
 * gen.next().value; // 2
 */