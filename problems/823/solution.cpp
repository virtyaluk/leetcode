const int MOD = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long int ans = 0;
        unordered_map<int, long long int> dp;
        
        sort(begin(arr), end(arr));
        
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
                }
            }
            
            ans = (ans + dp[arr[i]]) % MOD;
        }
        
        return ans % MOD;
    }

    int numFactoredBinaryTrees1(vector<int>& arr) {
        long long int ans = 0;
        unordered_set<int> us(begin(arr), end(arr));
        unordered_map<int, long long int> memo;
        
        for (const int& num: arr) {
            ans += dfs(arr, num, us, memo);
        }
        
        return ans % MOD;
    }
    
    long long int dfs(const vector<int>& arr, int num, const unordered_set<int>& us, unordered_map<int, long long int>& memo) {
        if (memo.count(num)) {
            return memo[num];
        }
        
        long long int count = 1;
        
        for (const int& x: arr) {
            if (num % x == 0 and us.count(num / x)) {
                count += dfs(arr, x, us, memo) * dfs(arr, num / x, us, memo);
            }
        }
        
        return memo[num] = count;
    }
};