class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = size(rains);
        vector<int> ans(n);
        set<int> dryDays;
        unordered_map<int, int> fullLakes;
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                
                if (fullLakes.count(lake)) {
                    auto it = dryDays.lower_bound(fullLakes[lake]);
                    
                    if (it == end(dryDays)) {
                        return {};
                    }
                    
                    ans[*it] = lake;
                    dryDays.erase(*it);
                }
                
                ans[i] = -1;
                fullLakes[lake] = i;
            }
        }
        
        return ans;
    }
};