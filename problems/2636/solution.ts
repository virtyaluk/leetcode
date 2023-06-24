type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
    let next = () => functions[n++]?.().then(next);
    
    return Promise.all(functions.slice(0, n).map(f => f().then(next)));
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */