class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a = 0;
        
        while (a * a <= c) {
            double b = sqrt(c - a * a);
            
            if (b == (int) b) {
                return true;
            }
            
            a++;
        }
        
        return false;
    }
};