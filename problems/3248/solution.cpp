class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        
        for (const string& c: commands) {
            if (c == "UP") {
                ans -= n;
            } else if (c == "DOWN") {
                ans += n;
            } else if (c == "RIGHT") {
                ans++;
            } else if (c == "LEFT") {
                ans--;
            }
        }
        
        return ans;
    }
};