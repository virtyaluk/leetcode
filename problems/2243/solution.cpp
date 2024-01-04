class Solution {
public:
    string digitSum(string s, int k) {
        if (size(s) <= k) {
            return s;
        }
        
        string ans;
        
        for (int i = 1, sum = 0; i <= size(s); i++) {
            sum += s[i - 1] - '0';
            
            if (i % k == 0 or i == size(s)) {
                ans += to_string(sum);
                sum = 0;
            }
        }
        
        return digitSum(ans, k);
    }
};