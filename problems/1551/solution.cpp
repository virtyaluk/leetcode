class Solution {
public:
    int minOperations(int n) {
        int ans = 0, mid = n & 1 ? n / 2 : n / 2 - 1;

        for (int i = 0; i <= mid; i++) {
            ans += n - ((2 * i) + 1);
        }
        
        return ans;
    }
};