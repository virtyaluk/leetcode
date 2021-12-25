class Solution {
private:
    int dp[2001][2001];
    
    int helper(const vector<int>& arr1, const vector<int>& arr2, int i, int j, int prev) {
        if (i == size(arr1)) {
            return 0;
        }
        
        j = upper_bound(begin(arr2), end(arr2), prev) - begin(arr2);
        
        if (arr1[i] <= prev and j == size(arr2)) {
            return 1e9;
        }
        
        if (dp[i][j] == -1) {
            int take = 1e9, skip = 1e9;
            
            if (j != size(arr2)) {
                take = 1 + helper(arr1, arr2, i + 1, j + 1, arr2[j]);
            }
            
            if (arr1[i] > prev) {
                skip = helper(arr1, arr2, i + 1, j, arr1[i]);
            }
            
            dp[i][j] = min(take, skip);
        }
        
        return dp[i][j];
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp, -1, sizeof(dp));
        sort(begin(arr2), end(arr2));
        
        int ans = helper(arr1, arr2, 0, 0, -1);
        
        if (ans > size(arr1)) {
            return -1;
        }
        
        return ans;
    }
};