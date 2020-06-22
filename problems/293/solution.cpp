class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        
        for (int i = 1; i < size(s); i++) {
            if (s[i] == s[i - 1] and s[i] == '+') {
                s[i] = s[i - 1] = '-';
                
                ans.push_back(s);
                
                s[i] = s[i - 1] = '+';
            }
        }
        
        return ans;
    }
};