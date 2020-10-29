class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = size(nums), sum = 0;
        unordered_map<int, int> um = {{0, -1}};
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= k;
            
            if (um.count(sum)) {
                if (i - um[sum] > 1) {
                    return true;
                }
            } else {
                um[sum] = i;
            }
        }
        
        return false;
    }
};