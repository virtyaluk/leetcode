class Solution {
private:
    void dfs(string cur, const int& n, vector<string>& ans) {
        if (size(cur) == n) {
            ans.push_back(cur);
            
            return;
        }
        
        dfs(cur + "1", n, ans);
        
        if (empty(cur) or cur.back() == '1') {
            dfs(cur + "0", n, ans);
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        
        dfs("", n, ans);
        
        return ans;
    }
};