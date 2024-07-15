class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0,
            cur = 0;
        
        for (const char& ch: s) {
            if (ch == 'E') {
                cur++;
            } else {
                cur--;
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};