class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
        
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};