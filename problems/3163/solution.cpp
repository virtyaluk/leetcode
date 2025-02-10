class Solution {
public:
    string compressedString(string word) {
        string ans;
        vector<pair<char, int>> vp;
        
        vp.push_back({word.front(), 1});
        
        for (int i = 1; i < size(word); i++) {
            if (vp.back().first != word[i]) {
                vp.push_back({word[i], 0});
            }
            
            vp.back().second++;
        }
        
        for (int i = 0; i < size(vp); i++) {
            while (vp[i].second > 0) {
                int cnt = min(vp[i].second, 9);
                
                ans += to_string(cnt);
                ans.push_back(vp[i].first);
                
                vp[i].second -= cnt;
            }
        }
        
        return ans;
    }
};