class Solution {
public:
    bool isThree(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans += n % i == 0;
        }

        return ans == 3;
    }
};