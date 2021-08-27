class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, depth = 0;
        
        for (int i = 0; i < S.size(); i++) {
            const char& ch = S[i];
            
            if (ch == '(') {
                depth++;
            } else {
                depth--;
                
                if (S[i - 1] == '(') {
                    ans += 1 << depth;
                }
            }
        }
        
        return ans;
    }
    
    int scoreOfParentheses2(string S) {
        stack<int> st;
        st.push(0);
        
        for (const char& ch: S) {
            if (ch == '(') {
                st.push(0);
            } else {
                int score = max(2 * st.top(), 1);
                st.pop();
                st.top() += score;
            }
        }
        
        return st.top();
    }
    
    int scoreOfParentheses1(string S) {
        vector<int> st = {0};
        st.reserve(26);
        
        for (const char& ch: S) {
            if (ch == '(') {
                st.push_back(0);
            } else {
                int score = max(2 * st.back(), 1);
                st.pop_back();
                st.back() += score;
            }
        }
        
        return st.back();
    }
};