class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        
        string ans;
        
        while (n) {
            if (n % -2 == 0) {
                ans = "0" + ans;
            } else {
                n--;
                ans = "1" + ans;
            }
            
            n /= -2;
        }
        
        return ans;
    }
};