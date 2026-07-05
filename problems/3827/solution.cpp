class Solution {
public:
    int countMonobit(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 0;

        for (int i = 0; i <= n;) {
            i <<= 1;
            i += 1;
            ans++;
        }

        return ans;
    }
};