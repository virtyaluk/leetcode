class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        map<int, int> m{{0, 0}};
        
        for (int i = 0; i < size(scores); i++) {
            players.push_back({scores[i], ages[i]});
        }
        
        sort(begin(players), end(players));
        
        for (auto& [score, age]: players) {
            auto it0 = m.upper_bound(age);
            int newScore = score + (--it0)->second;
            auto it1 = m.insert(it0, {age, newScore});
            
            if (it1->second < newScore) {
                it1->second = newScore;
            }
            
            ++it1;
            
            while (it1 != end(m) and it1->second <= newScore) {
                auto it2 = it1++;
                m.erase(it2);
            }
        }
        
        return rbegin(m)->second;
    }
};