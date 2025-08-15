class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        long long sum = 0;
        unordered_map<long long, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (sum == k) {
                ans = i + 1;
            } else if (m.find(sum - k) != m.end()) {
                ans = max(ans, i - m[sum - k]);
            }
            
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        
        return ans;
    }
};