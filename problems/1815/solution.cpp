const int BS_SIZE = 30 * 9;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize);
        bitset<BS_SIZE> bs;
        unordered_map<bitset<BS_SIZE>, int> dp;
        
        for (const int& group: groups) {
            cnt[group % batchSize]++;
        }
        
        for (int i = 1; i < size(cnt); i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                bs[i * 30 + j] = 1;
            }
        }
        
        // cout << bs.to_string() << endl;
        // cout << bs.none() << endl;
        
        return cnt.front() + dfs(dp, cnt, bs, 0);
    }
    
    int dfs(
        unordered_map<bitset<BS_SIZE>, int>& dp,
        vector<int>& cnt,
        bitset<30 * 9>& bs,
        int left
    ) {
        if (bs.none()) {
            return 0;
        }
        
        if (dp.count(bs)) {
            return dp[bs];
        }
        
        int ans = 0,
            cur = left % size(cnt) == 0 ? 1 : 0;
        
        for (int i = 1; i < size(cnt); i++) {
            if (cnt[i] <= 0) {
                continue;
            }
            
            bs[i * 30 + cnt[i]] = 0;
            cnt[i]--;
            
            ans = max(ans, dfs(dp, cnt, bs, left + i));
            
            cnt[i]++;
            bs[i * 30 + cnt[i]] = 1;
        }
        
        return dp[bs] = ans + cur;
    }
};