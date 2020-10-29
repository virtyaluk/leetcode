class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = size(score);
        vector<string> ans(n);
        vector<pair<int, int>> ranks;
        
        for (int i = 0; i < n; i++) {
            ranks.push_back({score[i], i});
        }
        
        sort(begin(ranks), end(ranks), greater<>());
        
        for (int i = 0; i < n; i++) {
            string strRank;
            int j = i + 1;
            
            if (j == 1) {
                strRank = "Gold Medal";
            } else if (j == 2) {
                 strRank = "Silver Medal";
            } else if (j == 3) {
                strRank = "Bronze Medal";
            } else {
                strRank = to_string(j);
            }
            
            ans[ranks[i].second] = strRank;
        }
        
        return ans;
    }
};