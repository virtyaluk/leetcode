class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0,
            cur = 0;
        unordered_map<int, int> um;
        
        for (int i = 0; i < k; i++) {
            cur += nums[i];
            um[nums[i]]++;
        }
        
        if (size(um) == k) {
            ans = max(ans, cur);
        }
        
        for (int i = k; i < size(nums); i++) {
            cur += nums[i];
            um[nums[i]]++;
            
            cur -= nums[i - k];
            um[nums[i - k]]--;
            
            if (not um[nums[i - k]]) {
                um.erase(nums[i - k]);
            }
            
            if (size(um) == k) {
                ans = max(ans, cur);
            }
        }
        
        return ans;
    }
};