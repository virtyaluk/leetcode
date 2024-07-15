class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        
        for (const int& num: nums) {
            ans += num < k;
        }
        
        return ans;
    }
};