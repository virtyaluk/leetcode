class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (not numerator) {
            return "0";
        }
        
        string ans;
        unordered_map<long, int> um;
        
        if (numerator > 0 ^ denominator > 0) {
            ans.push_back('-');
        }
        
        long num = labs(numerator), den = labs(denominator), rem = num % den;
        
        ans += to_string(num/den);
        
        if (not rem) {
            return ans;
        }
        
        ans.push_back('.');
        
        while (rem) {
            if (um.find(rem) != end(um)) {
                ans.insert(um[rem], "(");
                ans.push_back(')');
                break;
            }
            
            um[rem] = size(ans);
            rem *= 10;
            ans += to_string(rem/den);
            rem %= den;
        }
        
        return ans;
    }
};