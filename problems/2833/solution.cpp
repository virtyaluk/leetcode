class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0,
            vacant = 0;
        
        for (const char& ch: moves) {
            if (ch == 'L') {
                ans--;
            } else if (ch == 'R') {
                ans++;
            } else {
                vacant++;
            }
        }
        
        return abs(ans) + vacant;
    }
};