class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        
        for (int i = 1; i < size(s); i++) {
            ans += abs(s[i] - s[i - 1]);
        }
        
        return ans;
    }
};