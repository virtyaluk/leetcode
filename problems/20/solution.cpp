class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        for (const char& ch: s) {
            if (m.find(ch) != m.end()) {
                st.push(m[ch]);
            } else {
                if (st.empty() || st.top() != ch) {
                    return false;
                }
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};