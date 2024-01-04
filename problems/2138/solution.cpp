class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans = {};
        string group;
        
        for (int i = 1; i <= size(s); i++) {
            group.push_back(s[i - 1]);
            
            if (i % k == 0 or i == size(s)) {
                ans.push_back(group);
                group.clear();
            }
        }
        
        while (size(ans.back()) != k) {
            ans.back().push_back(fill);
        }
        
        return ans;
    }
};