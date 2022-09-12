class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            
            if (str < ans) {
                ans = str;
            }
            
            string one = firstOp(str, a);
            
            if (visited.find(one) == visited.end()) {
                visited.insert(one);
                q.push(one);
            }
            
            string two = secondOp(str, b);
            
            if (visited.find(two) == visited.end()) {
                visited.insert(two);
                q.push(two);
            }
        }
        
        return ans;
    }
    
    string firstOp(string s, int a) {
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 != 0) {
                int digit = (s[i] - '0' + a) % 10;
                s[i] = digit + '0';
            }
        }
        
        return s;
    }
    
    string secondOp(string s, int b) {
        b %= s.size();
        
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        
        return s;
    }
};