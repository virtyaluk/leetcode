class Solution {
public:
    int minFlipsMonoIncr1(string s) {
        int onesCount = 0, flipCount = 0;
        
        for (const char& ch: s) {
            if (ch == '1') {
                onesCount++;
            } else {
                flipCount++;
            }
            
            flipCount = min(flipCount, onesCount);
        }
        
        return flipCount;
    }
    
    int minFlipsMonoIncr(string s) {
        int ans = INT_MAX, n = size(s);
        vector<int> zeros(n + 1), ones(n + 1);
        
        for (int i = 1, j = n - 1; j >= 0; i++, j--) {
            ones[i] = ones[i - 1] + (s[i - 1] == '1');
            zeros[j] = zeros[j + 1] + (s[j] == '0');
        }
        
        for (int i = 0; i <= n; i++) {
            ans = min(ans, ones[i] + zeros[i]);
        }
        
        return ans;
    }
};