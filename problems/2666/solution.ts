function once<T extends (...args: any[]) => any> (fn: T): ((...args: Parameters<T>) => ReturnType<T> | undefined) {
    let callCnt = 0;
  return function (...args) {
    if (callCnt < 1) {
        callCnt++;
        
        return fn(...args);
    }
      
      return undefined;
  };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */