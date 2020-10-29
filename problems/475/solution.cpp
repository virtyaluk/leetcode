class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        
        sort(begin(heaters), end(heaters));
        
        for (int i = 0; i < size(houses); i++) {
            auto it = lower_bound(begin(heaters), end(heaters), houses[i]);
            int dist = INT_MAX;
            
            if (it != end(heaters)) {
                dist = min(dist, *it - houses[i]);
            }
            
            if (it != begin(heaters)) {
                dist = min(dist, houses[i] - *(it - 1));
            }
            
            ans = max(ans, dist);
        }
        
        return ans;
    }
};