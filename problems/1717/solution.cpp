class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0, m = min(x, y), M = max(x, y);
        char first = x > y ? 'a' : 'b', second = x > y ? 'b' : 'a';
        stack<char> st1, st2;
        
        for (char& ch: s) {
            if (!st1.empty() && ch == second && st1.top() == first) {
                st1.pop();
                ans += M;
            } else {
                st1.push(ch);
            }
        }
        
        while (!st1.empty()) {
            char ch = st1.top();
            st1.pop();
            
            if (!st2.empty() && ch == second && st2.top() == first) {
                st2.pop();
                ans += m;
            } else {
                st2.push(ch);
            }
        }
        
        return ans;
    }
};