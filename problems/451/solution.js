/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    const m = {};
    
    for (let ch of s) {
        if (!m[ch]) {
            m[ch] = 0;
        }
        
        m[ch]++;
    }
    
    const buckets = new Array(Object.keys(m).length + 1);
    
    for (let key of Object.keys(m)) {
        const val = m[key];
        
        if (!buckets[val]) {
            buckets[val] = [];
        }
        
        buckets[val].push(key);
    }
    
    let ans = '';
    
    for (let i = buckets.length - 1; i >= 0 ; i--) {
        if (!buckets[i] || !buckets[i].length) {
            continue;
        }
        
        for (let ch of buckets[i]) {
            ans += ch.repeat(i);
        }
    }
    
    return ans;
};