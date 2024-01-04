class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, last = -1;
        
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) > 0) {
                if (last >= 0) {
                    ans = max(ans, i - last);
                }
                
                last = i;
            }
        }
        
        return ans;
    }
};