/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    const ar = [];
    
    for (let i = 0; i < nums.length; i += 2) {
        let freq = nums[i];
        const val = nums[i + 1];
        
        while (freq > 0) {
            ar.push(val);
            freq--;
        }
    }
    
    return ar;
};