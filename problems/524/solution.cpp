class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        
        for (const string& str: d) {
            int i = 0;
            
            for (const char& ch: s) {
                if (i < str.size() and str[i] == ch) {
                    i++;
                }
            }
            
            if (i >= str.size() and ((str.size() > ans.size()) or (str.size() == ans.size() && str < ans))) {
                ans = str;
            }
        }
        
        return ans;
    }
};