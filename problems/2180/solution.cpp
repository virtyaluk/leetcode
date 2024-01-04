class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        
        for (int i = 1; i <= num; i++) {
            int x = i,
                sum = 0;
            
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            
            ans += sum % 2 == 0;
        }
        
        return ans;
    }
};