class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        
        sort(begin(happiness), end(happiness), greater<>());
        
        for (int i = 0, dec = 0; i < k; i++) {
            ans += max(happiness[i] - dec, 0);
            dec++;
        }
        
        return ans;
    }
};