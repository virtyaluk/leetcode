class Solution {
public:
    string thousandSeparator(int n) {
        if (n < 1000) {
            return to_string(n);
        }
        
        string ans = "";
        int i = 0;
        
        while (n) {
            i++;
            ans = to_string(n % 10) + ans;
            n /= 10;
            
            if (i % 3 == 0 && n) {
                ans = "." + ans;
            }
        }
        
        return ans;
    }
};