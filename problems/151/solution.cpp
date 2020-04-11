class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, k = 0, wordsCounter = 0;

        while (true) {
            while (i < s.size() and s[i] == ' ') {
                i++;
            }
            
            if (i == s.size()) {
                break;
            }
            
            if (wordsCounter) {
                s[j++] = ' ';
            }
            
            k = j;
            
            while (i < s.size() and s[i] != ' ') {
                s[j++] = s[i++];
            }
            
            str_reverse(s, k, j - 1);
            
            wordsCounter++;
        }
        
        s.resize(j);
        str_reverse(s, 0, j - 1);
        
        return s;
    }
    
    void str_reverse(string& s, int lo, int hi) {
        while (lo < hi) {
            swap(s[lo++], s[hi--]);
        }
    }
    
    string reverseWords1(string s) {
        string ans = "", token = "";
        vector<string> tokens;
        
        for (const char& ch: s) {
            if (ch == ' ') {
                if (not token.empty()) {
                    tokens.push_back(token);
                }
                
                token = "";
            } else {
                token += ch;
            }
        }
        
        if (not token.empty()) {
            tokens.push_back(token);
        }
        
        for (int i = tokens.size() - 1; i >= 0; i--) {
            ans += tokens[i];
            
            if (i > 0) {
                ans += " ";
            }
        }
        
        return ans;
    }
};