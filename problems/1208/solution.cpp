class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        
        for (int i = 0, j = 0, curCost = 0; j < size(s); j++) {
            curCost += abs(s[j] - t[j]);
            
            while (curCost > maxCost) {
                curCost -= abs(s[i] - t[i]);
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};