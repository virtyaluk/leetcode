class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        
        for (int i = 0; i < size(s); i += 2) {
            ans += s[i] != s[i + 1];
        }
        
        return ans;
    }
};