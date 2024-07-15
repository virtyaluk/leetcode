class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0,
            n = size(nums),
            m = size(pattern);
        
        for (int i = 0; i < n - m; i++) {
            int lenCheck = 0;
            
            for (int k = 0; k < m; k++) {
                if (
                    (pattern[k] == 1 and nums[i + k + 1] > nums[i + k])
                    or
                    (pattern[k] == 0 and nums[i + k + 1] == nums[i + k])
                    or
                    (pattern[k] == -1 and nums[i + k + 1] < nums[i + k])
                    ) {
                    lenCheck++;
                } else {
                    break;
                }
            }
            
            ans += lenCheck == m;
        }
        
        return ans;
    }
};