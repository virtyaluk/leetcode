class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string, int> m;
        
        if (s.empty() || s.size() < 10) {
            return ans;
        }
        
        for (int i = 0; i < s.size() - 9; i++) {
            string substr = s.substr(i, 10);
            m[substr]++;
        }
        
        for (auto [seq, count]: m) {
            if (count > 1) {
                ans.push_back(seq);
            }
        }
        
        return ans;
    }
};