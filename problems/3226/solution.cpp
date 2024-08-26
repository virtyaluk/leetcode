class Solution {
public:
    int minChanges(int n, int k) {
        bitset<32> nbs(n), kbs(k);
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            if (not nbs[i] and not kbs[i]) {
                continue;
            }
            
            if (not nbs[i] and kbs[i]) {
                return -1;
            }
            
            if (nbs[i] and not kbs[i]) {
                ans++;
            }
        }
        
        return ans;
    }
};