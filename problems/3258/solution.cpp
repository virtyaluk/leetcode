class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        
        for (int lo = 0, hi = 0, ones = 0; hi < size(s); hi++) {
            ones += s[hi] == '1';

            while (ones > k && (hi - lo + 1 - ones) > k) {
                ones -= s[lo++] == '1';
            }

            ans += (hi - lo + 1);
        }

        return ans;
    }
};