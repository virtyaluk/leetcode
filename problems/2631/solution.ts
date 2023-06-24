declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn) {
    let ans = {};
    
    for (let i = 0; i < this.length; i++) {
        const key = fn(this[i]);
        
        if (!ans.hasOwnProperty(key)) {
            ans[key] = [];
        }
        
        ans[key].push(this[i]);
    }
    
    return ans;
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */