class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = 'a';
        
        for (int i = 0, prevTime = 0, largestTime = 0; i < size(releaseTimes); i++) {
            int curTime = releaseTimes[i] - prevTime;
            prevTime = releaseTimes[i];
            
            if (curTime == largestTime) {
                ans = max(ans, keysPressed[i]);
            }
            
            if (curTime > largestTime) {
                largestTime = curTime;
                ans = keysPressed[i];
            }
        }
        
        return ans;
    }
};