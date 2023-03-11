class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int m = size(potions);
        
        sort(begin(potions), end(potions));
        
        for (const int& spell: spells) {
            long long x = ceil((success * 1.0) / spell);
            
            if (x > potions.back()) {
                ans.push_back(0);
                continue;
            }
            
            auto it = lower_bound(begin(potions), end(potions), x) - begin(potions);
            
            ans.push_back(m - it);
        }
        
        return ans;
    }
};