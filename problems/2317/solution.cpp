class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        
        for (const int& num: nums) {
            ans |= num;
        }
        
        return ans;
    }
};