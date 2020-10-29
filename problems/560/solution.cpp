class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> um = {{0, 1}};
        
        for (const int& num: nums) {
            sum += num;
            ans += um[sum - k];
            um[sum]++;
        }
        
        return ans;
    }
};