class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) {
            return 0;
        }
        
        int ans = 1, curLen = 1;
        
        for (int i = 1; i < s.size(); i++) {
            curLen = s[i] == s[i - 1] ? curLen + 1 : 1;
            ans = max(ans, curLen);
        }
        
        return ans;
    }
};