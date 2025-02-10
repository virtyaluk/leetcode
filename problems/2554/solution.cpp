class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        unordered_set<int> us(begin(banned), end(banned));
        
        for (int i = 1; i <= n and maxSum > 0; i++) {
            if (us.count(i)) {
                continue;
            }
            
            if (maxSum - i < 0) {
                return ans;
            }
            
            maxSum -= i;
            ans++;
        }
        
        return ans;
    }
};