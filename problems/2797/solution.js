/**
 * @param {Function} fn
 * @param {Array} args
 * @return {Function}
 */
var partial = function(fn, args) {
    
    return function(...restArgs) {
        const replacedArgs = args.map(arg => arg === '_' ? restArgs.shift() : arg);
        return fn(...replacedArgs.concat(restArgs));
    }
};