class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0, m = nums.front(), M = nums.front(); i < size(nums); i++) {
            m = min(m, nums[i]);
            M = max(m, nums[i]);
            
            if (M - m > k) {
                ans++;
                m = M = nums[i];
            }
        }
        
        return ans;
    }
};