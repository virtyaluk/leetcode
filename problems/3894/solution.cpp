class Solution {
public:
    string trafficSignal(int timer) {
        if (not timer) {
            return "Green";
        } else if (timer == 30) {
            return "Orange";
        } else if (timer > 30 and timer <= 90) {
            return "Red";
        }

        return "Invalid";
    }
};