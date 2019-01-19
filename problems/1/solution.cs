public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var d = new Dictionary<int, int>();
        
        for (var i = 0; i < nums.Length; i++) {
            var compl = target - nums[i];
            
            if (d.ContainsKey(compl)) {
                return new int[] {d[compl], i};
            }
            
            d[nums[i]] = i;
        }
        
        return new int[]{};
    }
}