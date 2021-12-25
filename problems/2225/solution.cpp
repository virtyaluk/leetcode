class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, bool> winners;
        unordered_map<int, int> losers;
        vector<vector<int>> ans(2);
        
        for (const vector<int>& match: matches) {
            int winner = match.front(),
                loser = match.back();
            
            if (not winners.count(winner) and not winners[winner]) {
                winners[winner] = true;
            }
            
            winners[loser] = false;
            losers[loser]++;
        }
        
        for (auto [player, isWinner]: winners) {
            if (isWinner) {
                ans.front().push_back(player);
            }
        }
        
        for (auto [player, cnt]: losers) {
            if (cnt == 1) {
                ans.back().push_back(player);
            }
        }
        
        sort(begin(ans.front()), end(ans.front()));
        sort(begin(ans.back()), end(ans.back()));
        
        return ans;
    }
};