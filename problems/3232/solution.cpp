class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a = 0, b = 0;
        
        for (const int& num: nums) {
            if (num < 10) {
                a += num;
            } else {
                b += num;
            }
        }
        
        return abs(a - b) >= 1;
    }
};