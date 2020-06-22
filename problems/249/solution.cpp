class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, int> um;
        
        for (const string& str: strings) {
            string h;
            int dif = str[0] - 'a';
            
            for (const char& ch: str) {
                char key = ch - dif;
                
                if (key < 'a') {
                    key += 26;
                }
                
                h += key;
            }
            
            if (not um.count(h)) {
                um[h] = size(um);
                ans.push_back({});
            }
            
            ans[um[h]].push_back(str);
        }
        
        return ans;
    }
};