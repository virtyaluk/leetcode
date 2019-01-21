class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") {
            return "0";
        }
        
        int n = size(num1), m = size(num2);
        string ans(n + m, '0');
        
        for (int i = n - 1; i >= 0; i--) {
            int carry = 0, n1 = num1[i] - '0';

            for (int j = m - 1; j >= 0; j--) {
                int val = (ans[i + j + 1] - '0') + carry + (num2[j] - '0') * n1;
                ans[i + j + 1] = val % 10 + '0';
                carry = val / 10;
            }
            
            ans[i] += carry;
        }
        
        for (int i = 0; i < n + m; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        
        return "0";
    }
};

/*

    456
    123
      =
   1368
   912
  456
  56088

*/