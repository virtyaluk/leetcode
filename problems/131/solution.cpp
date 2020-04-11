class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curList;
        
        backtrack(ans, curList, s, 0);
        
        return ans;
    }
    
    void backtrack(vector<vector<string>>& ans, vector<string>& curList, string& s, int start) {
        if (start >= s.size()) {
            ans.push_back(curList);
        }
        
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curList.push_back(s.substr(start, end - start + 1));
                
                backtrack(ans, curList, s, end + 1);
                
                curList.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) {
                return false;
            }
        }
        
        return true;
    }
};