/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = Math.max(0, i - k); j < i; j++) {
            if (Math.abs(nums[i] - nums[j]) <= t) {
                return true;
            }
        }
    }
    
    return false;
};