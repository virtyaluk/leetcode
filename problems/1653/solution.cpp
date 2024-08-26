class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        stack<char> st;
        
        for (const char& ch: s) {
            if (not empty(st) and st.top() == 'b' and ch == 'a') {
                st.pop();
                ans++;
            } else {
                st.push(ch);
            }
        }
        
        return ans;
    }
};