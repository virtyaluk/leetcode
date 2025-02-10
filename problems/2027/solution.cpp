class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        
        for (int i = 0; i < size(s);) {
            if (s[i] == 'O') {
                i++;
            } else {
                ans++;
                i += 3;
            }
        }
        
        return ans;
    }
};