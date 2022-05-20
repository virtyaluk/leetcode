class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cur = accumulate(begin(cardPoints), begin(cardPoints) + k, 0), ans = cur, n = size(cardPoints);
        
        for (int i = 0; i < k; i++) {
            cur -= cardPoints[k - i - 1];
            cur += cardPoints[n - i - 1];
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};