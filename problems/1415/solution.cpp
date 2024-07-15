const vector<char> abc{'a', 'b', 'c'};

class Solution {
private:
    void dfs(vector<string>& dp, string& cur, int n, int k) {
        if (size(dp) == k) {
            return;
        }
        
        if (size(cur) == n) {
            dp.push_back(cur);
            return;
        }
        
        for (const char& ch: abc) {
            if (empty(cur) or cur.back() != ch) {
                cur.push_back(ch);
                
                dfs(dp, cur, n, k);
                
                cur.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> dp;
        string cur;
        
        dfs(dp, cur, n, k);
        
        if (size(dp) == k) {
            return dp.back();
        } else {
            return "";
        }
    }
};