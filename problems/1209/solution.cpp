class Solution {
public:
    string removeDuplicates(string s, int k) {
        int j = 0;
        stack<int> st;
        
        for (int i = 0; i < size(s); i++, j++) {
            s[j] = s[i];
            
            if (j == 0 or s[j] != s[j - 1]) {
                st.push(1);
            } else if (++st.top() == k) {
                j -= k;
                st.pop();
            }
        }
        
        return s.substr(0, j);
    }
};