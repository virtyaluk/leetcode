class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long int ans = 0,
            sum = 0;
        
        for (const int& num: nums) {
            sum += num;
            ans |= num;
            ans |= sum;
        }
        
        return ans;
    }
};