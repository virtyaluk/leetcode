class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[abs(num)] |= 1 << (num < 0);
        }
        
        for (auto [num, bs]: um) {
            if (bs == 3) {
                ans = max(ans, num);
            }
        }
        
        return ans;
    }
};