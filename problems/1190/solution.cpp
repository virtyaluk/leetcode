class Solution {
public:
    string reverseParentheses(string s) {
        int n = size(s), j = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                reverse(s, st.top() + 1, i - 1);
                st.pop();
            }
        }
        
        for (int i = 0; i < n; i++) {
            s[j] = s[i];
            j += s[i] != '(' and s[i] != ')';
        }
        
        s.erase(j, string::npos);
        
        return s;//.substr(0, j);
    }
    
    void reverse(string& s, int lo, int hi) {
        while (lo <= hi) {
            swap(s[lo++], s[hi--]);
        }
    }
};