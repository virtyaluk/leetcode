class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;
        vector<int> ans;
        
        for (const vector<int>& rest: restaurants) {
            if (!rest[2] and veganFriendly) {
                continue;
            }
            
            if (rest[3] > maxPrice) {
                continue;
            }
            
            if (rest[4] > maxDistance) {
                continue;
            }
            
            filtered.push_back(rest);
        }
        
        sort(begin(filtered), end(filtered), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[1] == rhs[1]) {
                return lhs.front() > rhs.front();
            }
            
            return lhs[1] > rhs[1];
        });
        
        for (const vector<int>& rest: filtered) {
            ans.push_back(rest.front());
        }
        
        return ans;
    }
};