class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 0, cur = 0, i = 0;
        
        for (; i < k; i++) {
            cur += blocks[i] == 'B';
        }
        
        ans = k - cur;
        
        while (i < size(blocks)) {
            cur += blocks[i] == 'B';
            cur -= blocks[i - k] == 'B';
            i++;
            ans = min(ans, k - cur);
        }
        
        return ans;
    }
};