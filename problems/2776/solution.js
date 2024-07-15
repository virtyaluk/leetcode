
var promisify = function(fn) {
  return function(...args) {
    return new Promise((resolve, reject) => {
      function callback(result, error) {
        // If error, reject the Promise 
        if(error) {
          reject(error);
        // If no error, resolve the Promise
        } else {
          resolve(result);
        }
      }

      fn(callback, ...args);
    });
  };
};
