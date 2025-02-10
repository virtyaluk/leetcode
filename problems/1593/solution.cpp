class Solution {
private:
    void backtrack(const string& s, unordered_set<string>& seen, int start, int cur, int& ans) {
        if (cur + size(s) - start <= ans) {
            return;
        }
        
        if (start == size(s)) {
            ans = max(ans, cur);
            
            return;
        }
        
        for (int i = start + 1; i <= size(s); i++) {
            string str = s.substr(start, i - start);
            
            if (seen.find(str) == end(seen)) {
                seen.insert(str);
                
                backtrack(s, seen, i, cur + 1, ans);
                
                seen.erase(str);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int ans = 0;
        unordered_set<string> seen;
        
        backtrack(s, seen, 0, 0, ans);
        
        return ans;
    }
};