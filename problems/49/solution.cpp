class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> abc;
        
        for (const string& str: strs) {
            string code(begin(str), end(str));
            
            sort(begin(code), end(code));
            
            if (not abc.count(code)) {
                ans.push_back({});
                abc[code] = size(ans) - 1;
            }
            
            ans[abc[code]].push_back(str);
        }
        
        return ans;
    }
};