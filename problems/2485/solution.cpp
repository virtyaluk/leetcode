class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1, left = 0, right = n * (n + 1) / 2; i <= n; i++) {
            left += i;
            
            if (left == right) {
                return i;
            }
            
            right -= i;
        }
        
        return -1;
    }
};