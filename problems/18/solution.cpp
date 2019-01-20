class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums1, int t) {
        int n = size(nums1);
        vector<vector<int>> ans;
        
        if (n < 4) {
            return ans;
        }
        
        long long int target = t;
        vector<long long int> nums(begin(nums1), end(nums1));
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < n - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }
            
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < n - 2; j++) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                
                if (j > i + 1 and nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int lo = j + 1, hi = n - 1;
                
                while (lo < hi) {
                    long long int cur = nums[i] + nums[j] + nums[lo] + nums[hi];
                    
                    if (cur == target) {
                        ans.push_back({
                            (int) nums[i],
                            (int) nums[j],
                            (int) nums[lo],
                            (int) nums[hi]
                            });
                        
                        while (lo < hi and nums[lo] == nums[lo + 1]) {
                            lo++;
                        }
                        
                        while (lo < hi and nums[hi] == nums[hi - 1]) {
                            hi--;
                        }
                        
                        lo++;
                        hi--;
                    } else if (cur < target) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        
        return ans;
    }
};