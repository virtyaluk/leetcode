class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        
        for (int i = size(s) - 1, cnt = 0; i >= 0; i--) {
            if (s[i] == '0') {
                cnt++;
            } else {
                ans += cnt;
            }
        }
        
        return ans;
    }
};