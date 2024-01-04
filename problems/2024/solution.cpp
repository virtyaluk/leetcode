class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int lo = 0,
            hi = 0,
            n = size(s),
            t = 0,
            f = 0,
            ans = 0;
        
        while (hi < n) {
            t += s[hi] == 'T';
            f += s[hi] == 'F';
            
            while (t > k and f > k) {
                if (s[lo] == 'T') {
                    t--;
                } else {
                    f--;
                }
                
                lo++;
            }
            
            ans = max(ans, hi - lo + 1);
            hi++;
        }
        
        return ans;
    }
};