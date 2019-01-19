public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var ans = new List<int[]>();
        
        Array.Sort(nums);
        
        for (var i = 0; i < nums.Length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            var a = nums[i];
            var lo = i + 1;
            var hi = nums.Length - 1;
            
            while (lo < hi) {
                var b = nums[lo];
                var c = nums[hi];
                var curSum = a + b + c;
                
                if (curSum == 0) {
                    ans.Add(new int[]{a, b, c});
                    
                    while (lo < hi && nums[lo] == nums[lo + 1]) {
                        lo++;
                    }
                    
                    while (lo < hi && nums[hi] == nums[hi - 1]) {
                        hi--;
                    }
                    
                    lo++;
                    hi--;
                } else if (curSum > 0) {
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        
        return ans.ToArray();
    }
}