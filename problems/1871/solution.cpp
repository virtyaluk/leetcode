class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = size(s);
        vector<int> dp(n),
            pre(n);
        dp.front() = 1;

        for (int i = 0; i < minJump; i++) {
            pre[i] = 1;
        }

        for (int i = minJump; i < n; i++) {
            int lo = i - maxJump,
                hi = i - minJump;
            
            if (s[i] == '0') {
                int total = pre[hi] - (lo <= 0 ? 0 : pre[lo - 1]);
                dp[i] = total != 0;
            }

            pre[i] = pre[i - 1] + dp[i];
        }

        return dp.back();
    }
};