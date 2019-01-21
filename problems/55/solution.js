/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let li = nums.length - 1;
    
    for (let i = nums.length - 2; i >= 0; i--) {
        if (i + nums[i] >= li) {
            li = i;
        }
    }
    
    return li == 0;
};