class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0,
                ball = i;
            
            while (ball) {
                sum += ball % 10;
                ball /= 10;
            }
            
            um[sum]++;
            
            if (um[sum] > um[ans]) {
                ans = sum;
            }
        }
        
        return um[ans];
    }
};