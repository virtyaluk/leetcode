class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                if (i - start + 1 >= 3) {
                    vector<int> g;
                
                    g.push_back(start);
                    g.push_back(i);
                    ans.push_back(g);
                }
                
                start = i + 1;
            }
        }
        
        return ans;
    }
};