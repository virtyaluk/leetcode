class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = size(nums);
        long long valid = 0;
        unordered_map<int, int> um;
        
        for (int i = 0; i < n; i++) {
            valid += um[i - nums[i]];
            um[i - nums[i]]++;
        }
        
        return 1ll * n * (n - 1) / 2- valid;
    }
};