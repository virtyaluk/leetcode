public class Solution {
    public bool CanJump(int[] nums) {
        var leftmostGoodIndex = nums.Length - 1;
        
        for (var i = nums.Length - 2; i >= 0; i--) {
            if (i + nums[i] >= leftmostGoodIndex) {
                leftmostGoodIndex = i;
            }
        }
        
        return leftmostGoodIndex == 0;
    }
}