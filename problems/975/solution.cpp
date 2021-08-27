class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int ans = 1, n = size(arr);
        vector<vector<bool>> dp(n, vector<bool>(2));
        map<int, int> m;
        
        dp.back() = {true, true};
        m[arr.back()] = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            auto it = m.lower_bound(arr[i]);
            
            if (it != end(m)) { // even jump
                ans += dp[i][0] = dp[it->second][1];
                
                if (it->first == arr[i]) {
                    it++;
                }
            }
            
            if (it != begin(m)) {
                dp[i][1] = dp[prev(it)->second][0];
            }
            
            m[arr[i]] = i;
        }
        
        return ans;
    }
};