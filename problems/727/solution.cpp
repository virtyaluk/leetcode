class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1, len = -1, ti = 0;
        
        for (int i = 0; i < size(s); i++) {
            if (s[i] == t[ti]) {
                ti++;
            }
            
            if (ti == size(t)) {
                int d = i;
                
                while (ti > 0) {
                    if (s[d] == t[ti - 1]) {
                        ti--;
                    }
                    
                    d--;
                }
                
                if (len == -1 or i - d < len) {
                    start = d + 1;
                    len = i - d;
                }
                
                i = d + 1;
            }
        }
        
        if (len == -1) {
            return "";
        }
        
        return s.substr(start, len);
    }
};