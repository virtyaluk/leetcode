class Solution {
public:
    int minCut(string s) {
        int n = size(s);
        vector<int> dp(n);
        
        iota(begin(dp), end(dp), 0);
        
        for (int mid = 0; mid < n; mid++) {
            findPalindrome(s, dp, mid, mid);
            findPalindrome(s, dp, mid - 1, mid);
        }
        
        return dp.back();
    }
    
    void findPalindrome(const string& s, vector<int>& dp, int lo, int hi) {
        while (lo >= 0 and hi < size(s) and s[lo] == s[hi]) {
            int startCut = lo == 0 ? 0 : dp[lo - 1] + 1;
            dp[hi] = min(dp[hi], startCut);
            lo--;
            hi++;
        }
    }
};