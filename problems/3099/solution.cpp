class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int ans = 0,
            y = x;
        
        while (y) {
            ans += y % 10;
            y /= 10;
        }
        
        if (x % ans == 0) {
            return ans;
        }
        
        return -1;
    }
};