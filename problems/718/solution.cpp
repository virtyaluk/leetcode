typedef long long int ll;

const int MOD = 1e9 + 7;
const int base = 107;

class Solution {
public:
    unordered_set<ll> rollingHash(vector<int>& nums, const vector<ll>& power, int len) {
        unordered_set<ll> ans;
        ll hash = 0;
        
        for (int i = 0; i < len; i++) {
            hash = (hash + (nums[i] * power[len - i]) % MOD) % MOD;
        }
        
        ans.insert(hash);
        
        for (int i = len; i < size(nums); i++) {
            hash = (hash - (nums[i - len] * power[len]) % MOD + MOD) % MOD; // remove prev char
            hash = (hash * base) % MOD; // shift one base left
            hash = (hash + (nums[i] * base) % MOD) % MOD; // add cur char
            
            ans.insert(hash);
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums1, vector<int>& nums2, const vector<ll>& powers, int len) {
        unordered_set<ll> firstHashes = rollingHash(nums1, powers, len);
        
        for (const ll& curHash: rollingHash(nums2, powers, len)) {
            if (firstHashes.count(curHash)) {
                return true;
            }
        }
        
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen = min(size(nums1), size(nums2)), lo = 1, hi = maxLen;
        vector<ll> powers = {1};
        
        for (int i = 0; i < maxLen; i++) {
            powers.push_back(powers.back() * base % MOD);
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(nums1, nums2, powers, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo - 1;
    }
    
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, m = size(nums1), n = size(nums2);
        vector<int> dp(n + 1);
        
        for (int i = 1; i <= m; i++) {
            vector<int> newDp(n + 1);
            
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    newDp[j] = dp[j - 1] + 1;
                    ans = max(ans, newDp[j]);
                }
            }
            
            dp = newDp;
        }
        
        return ans;
    }
    
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, m = size(nums1), n = size(nums2);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                } /*else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }*/
            }
        }
        
        return ans;
    }
};