class Solution {
public:
    string robotWithString(string s) {
        string ans;
        unordered_map<char, int> um;
        stack<char> st;
        char m = 'a';

        for (const char& ch: s) {
            um[ch]++;
        }

        for (const char& ch: s) {
            st.emplace(ch);
            um[ch]--;

            while (m != 'z' and um[m] == 0) {
                m++;
            }

            while (not empty(st) and st.top() <= m) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};