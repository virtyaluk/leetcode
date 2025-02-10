class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> um;
        long long prefSum = 0;
        optional<long long> ans;
        
        for (int i = 0; i < size(nums); i++) {
            prefSum += nums[i];
            int a = nums[i] + k,
                b = nums[i] - k;
            
            if (um.count(a)) {
                ans = ans.has_value() ? max(ans.value(), prefSum - um[a] + a) : prefSum - um[a] + a;
            }
            
            if (um.count(b)) {
                ans = ans.has_value() ? max(ans.value(), prefSum - um[b] + b) : prefSum - um[b] + b;
            }
            
            um[nums[i]] = min(prefSum, um.count(nums[i]) ? um[nums[i]] : LLONG_MAX);
        }
        
        return ans.value_or(0);
    }
};