/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    nums = nums.sort((a, b) => a - b );
    
    for (var i = 0; i < nums.length; i++) {
        if (nums[i] === nums[i + 1]) {
            return true;
        }
    }
    
    return false;
};