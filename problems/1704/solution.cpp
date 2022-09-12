class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        unordered_set<char> st {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for (int i = 0; i < s.size(); i++) {
            char& ch = s[i];
            
            
            
            if (st.find(ch) != st.end()) {
                if (i + 1 > s.size() / 2) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        
        return cnt == 0;
    }
};