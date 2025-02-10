class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> bs(num1), ans;
        int bits = __builtin_popcount(num2);

        for (int i = 30; i >= 0 and bits > 0; i--) {
            if (bs[i]) {
                ans[i] = true;
                bits--;
            }
        }

        for (int i = 0; i < 30 and bits > 0; i++) {
            if (not ans[i]) {
                ans[i] = true;
                bits--;
            }
        }

        return ans.to_ulong();
    }
};