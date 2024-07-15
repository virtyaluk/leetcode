class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        
        for (const int& num: nums) {
            int mod = num % 3;
            
            ans += min(mod, 3 - mod);
        }
        
        return ans;
    }
};