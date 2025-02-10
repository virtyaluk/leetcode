class Solution {
private:
    int check(int a, int b, int c) {
        int ans = 0,
            i = 0;

        while (a) {
            if (a & 1) {
                ans |= (1 << i);
            }

            i++;
            a >>= 1;
        }

        while (b) {
            if (b & 1) {
                ans |= (1 << i);
            }

            i++;
            b >>= 1;
        }

        while (c) {
            if (c & 1) {
                ans |= (1 << i);
            }

            i++;
            c >>= 1;
        }

        return ans;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        int a = nums[0],
            b = nums[1],
            c = nums[2];

        return max({
            check(a, b, c),
            check(a, c, b),
            check(b, a, c),
            check(b, c, a),
            check(c, a, b),
            check(c, b, a)
        });
    }
};