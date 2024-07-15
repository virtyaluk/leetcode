class Solution {
    int getTime(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
    
public:
    int convertTime(string current, string correct) {
        int ans = 0,
            totalMins = getTime(correct) - getTime(current),
            mins[4] = {60, 15, 5, 1};
        
        for (int nextMin : mins) {
            ans += totalMins / nextMin;
            totalMins %= nextMin;
        }
        
        return ans;
    }
};