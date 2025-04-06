class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < size(s); i++) {
            ans += (i + 1) * (26 - (s[i] - 'a'));
        }

        return ans;
    }
};