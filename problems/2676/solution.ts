type F = (...args: any[]) => void

function throttle(fn: F, t: number): F {
    let tid = null,
        restTime = 0;
    
  return function (...args) {
    const curTime = Date.now(),
          delay = Math.max(0, restTime - curTime);
      
      clearTimeout(tid);
      
      tid = setTimeout(() => {
          fn(...args);
          restTime = Date.now() + t;
      }, delay);
  }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */