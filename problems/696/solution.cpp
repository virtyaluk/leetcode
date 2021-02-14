class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, ones = 0, zeros = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (not i or s[i] == s[i - 1]) {
                if (s[i] == '1') {
                    ones++;
                } else {
                    zeros++;
                }
            } else {
                ans += min(ones, zeros);
                
                if (s[i] == '1') {
                    ones = 1;
                } else if (s[i] == '0') {
                    zeros = 1;
                }
            }
        }
        
        ans += min(ones, zeros);
        
        return ans;
    }
    
    int countBinarySubstrings1(string s) {
        int ans = 0;
        stack<pair<int, int>> st;
        
        st.push({0, 0});
        s += '.';
        
        for (int i = 0; i < s.size(); i++) {
            if (not i or s[i] == s[i - 1]) {
                if (s[i] == '1') {
                    st.top().first++;
                } else {
                    st.top().second++;
                }
            } else {
                ans += min(st.top().first, st.top().second);
                
                if (s[i] == '1') {
                    st.push({1, st.top().second});
                } else if (s[i] == '0') {
                    st.push({st.top().first, 1});
                }
            }
        }
        
        return ans;
    }
};