class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0, n = size(piles);
        
        sort(begin(piles), end(piles));
        
        for (int i = n / 3; i < n; i += 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};
