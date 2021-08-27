class Solution {
private:
    int modNeg(int num, int mod) {
        if (num < 0) {
            num = abs(num) % mod;
            
            return (-num + mod) % mod;
        }
        
        return num % mod;
    }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, cur = 0;
        unordered_map<int, int> um{{0, 1}};
        
        for (const int& num: nums) {
            cur = (cur + modNeg(num, k)) % k;
            ans += um[cur]++;
        }
        
        return ans;
    }
};