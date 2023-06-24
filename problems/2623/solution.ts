type Fn = (...params: any) => any

type sum = (a: number, b: number) => number
type fib = (a: number) => number
type fac = (a: number) => number
type f = sum & fib & fac

function memoize(fn: Fn): Fn {
    let cache: Map<string, number> = new Map();
    
    return function(...args) {
        const a = args.join(','),
              res = cache.has(a) ? cache.get(a) : fn(...args);
        
        if (!cache.has(a)) {
            cache.set(a, res);
        }
        
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */