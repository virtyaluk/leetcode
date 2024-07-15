class Solution {
private:
    int dfs(unordered_map<int, int>& dp, int num) {
        if (num == 1) {
            return 0;
        }
        
        if (not dp.count(num)) {
            if (num % 2 == 0) {
                dp[num] = 1 + dfs(dp, num / 2);
            } else {
                dp[num] = 1 + dfs(dp, 3 * num + 1);
            }
        }
        
        return dp[num];
    }
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> dp;
        vector<pair<int, int>> ans;
        
        for (int i = lo; i <= hi; i++) {
            ans.push_back({dfs(dp, i), i});
        }
        
        sort(begin(ans), end(ans));
        
        return ans[k - 1].second;
    }
};