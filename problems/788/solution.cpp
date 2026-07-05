class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int check = i;
            bool valid = true,
                changed = false;
            
            while (check > 0 and valid) {
                int d = check % 10;

                if (d == 3 or d == 4 or d == 7) {
                    valid = false;
                } else if (d == 2 or d == 5 or d == 6 or d == 9) {
                    changed = true;
                }

                check /= 10;
            }

            ans += (valid and changed);
        }

        return ans;
    }
};