class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        int num1 = 0, num2 = 0, i = 0;
        
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        sort(begin(digits), end(digits));
        
        while (i < size(digits)) {
            num1 = num1 * 10 + digits[i++];
            
            if (i < size(digits)) {
                num2 = num2 * 10 + digits[i++];
            }
        }
        
        return num1 + num2;
    }
};