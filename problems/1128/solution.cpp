class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const vector<int>& domino: dominoes) {
            int signature = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            
            um[signature]++;
        }
        
        for (auto &[ignore, val]: um) {
            ans += val * (val - 1) / 2;
        }
        
        return ans;
    }
};