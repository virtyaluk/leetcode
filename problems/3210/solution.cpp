class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans;
        
        for (int i = 0, n = size(s); i < n; i++) {
            ans.push_back(s[(i + k) % n]);
        }
        
        return ans;
    }
};