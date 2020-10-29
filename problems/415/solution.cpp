class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = size(num1), m = size(num2), i = n - 1, j = m - 1;
        bool carry = false;
        string ans;
        
        while (i >= 0 or j >= 0 or carry) {
            int curNum = carry;
            
            if (i >= 0) {
                curNum += (num1[i--] - '0');
            }
            
            if (j >= 0) {
                curNum += (num2[j--] - '0');
            }
            
            carry = curNum >= 10;
            curNum %= 10;
            
            ans = to_string(curNum) + ans;
        }
        
        return ans;
    }
};