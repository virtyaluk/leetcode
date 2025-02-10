class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        
        sort(begin(cost), end(cost));
        
        while (not empty(cost)) {
            if (not empty(cost)) {
                ans += cost.back();
                cost.pop_back();
            }
            
            if (not empty(cost)) {
                ans += cost.back();
                cost.pop_back();
            }
            
            if (not empty(cost)) {
                cost.pop_back();
            }
        }
        
        return ans;
    }
};