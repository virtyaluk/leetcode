class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        auto compare = [](pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.first + lhs.second < rhs.first + rhs.second;
        };
        
        int a = 0, b = 0;
        bool aTurn = true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> q(compare);
        
        for (int i = 0; i < aliceValues.size(); i++) {
            q.push({aliceValues[i], bobValues[i]});
        }
        
        while (!q.empty()) {
            auto [as, bs] = q.top();
            q.pop();
            
            if (aTurn) {
                a += as;
            } else {
                b += bs;
            }
            
            aTurn = !aTurn;
        }
        
        if (a == b) {
            return 0;
        }
        
        return a > b ? 1 : -1;
    }
};