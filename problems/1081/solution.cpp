class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        unordered_map<char, int> m;
        stack<char> st;
        set<char> seen;
        
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (seen.find(ch) == seen.end()) {
                while (!st.empty() && ch < st.top() && m[st.top()] > i) {
                    seen.erase(st.top());
                    st.pop();
                }
                
                seen.insert(ch);
                st.push(ch);
            }
        }
        
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};