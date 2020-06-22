class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < nums.size(); i++) {
            int lo = i + 1, hi = nums.size() - 1;
            
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                
                if (sum < target) {
                    ans += hi - lo;
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        
        return ans;
    }
};