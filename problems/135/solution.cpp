class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0, n = size(ratings);
        
        if (n <= 1) {
            return n;
        }
        
        vector<int> candies(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        ans = candies.back();
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            
            ans += candies[i];
        }
        
        return ans;
    }
};