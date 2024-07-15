class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0,
            cur = 0;
        
        for (const int& num: nums) {
            cur += num;
            ans += not cur;
        }
        
        return ans;
    }
};