class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0,
            flag = -1;
        
        for (const char& ch: directions) {
            if (ch == 'L') {
                if (flag >= 0) {
                    ans += flag + 1;
                    flag = 0;
                }
            } else if (ch == 'S') {
                if (flag > 0) {
                    ans += flag;
                }

                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
            }
        }

        return ans;
    }
};