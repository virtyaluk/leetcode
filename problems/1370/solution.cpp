class Solution {
public:
    string sortString(string s) {
        string ans = "";
        vector<int> chars(26, 0);
        
        for (char ch: s) {
            chars[ch - 'a']++;
        }
        
        while (true) {
            string cur = "";
            
            for (int i = 0; i < chars.size(); i++) {
                if (chars[i] > 0) {
                    cur += (char)('a' + i);
                    chars[i]--;
                }
            }
            
            for (int i = chars.size() - 1; i >= 0; i--) {
                if (chars[i] > 0) {
                    cur += (char)('a' + i);
                    chars[i]--;
                }
            }
            
            if (cur.empty()) {
                break;
            }
            
            ans += cur;
        }
        
        return ans;
    }
};