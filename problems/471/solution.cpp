class Solution {
private:
    unordered_map<string, string> dp;

public:
    string encode(string s) {
        if (dp.count(s)) {
            return dp[s];
        }
        
        string ans = s,
            tmp = s + s;
        
        auto it = tmp.find(s, 1);
        
        if (it != string::npos and it < size(s)) {
            cout << to_string(size(s) / it) << " : " << s << endl;
            ans = to_string(size(s) / it) + "[" + encode(s.substr(0, it)) + "]";
        }
        
        for (int i = 1; i < size(s); i++) {
            tmp = encode(s.substr(0, i)) + encode(s.substr(i));
            
            if (size(tmp) < size(ans)) {
                ans = tmp;
            }
        }
        
        return dp[s] = ans;
    }
};