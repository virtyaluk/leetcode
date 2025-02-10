class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        
        for (int i = 0; i < size(s); i += k) {
            int cur = 0;
            
            for (int j = 0; j < k; j++) {
                cur += s[i + j] - 'a';
            }
            
            cur %= 26;
            
            ans.push_back('a' + cur);
        }
        
        return ans;
    }
};