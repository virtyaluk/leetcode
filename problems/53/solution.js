/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let ans = nums[0];
    let current = -1;
    
    for (let num of nums) {
        current = current < 0 ? num : current + num;
        ans = current > ans ? current : ans;
    }
    
    return ans;
};