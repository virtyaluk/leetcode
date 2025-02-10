class Solution {
public:
    string reformat(string s) {
        string ans(size(s), '.');
        vector<char> digits, alphas;
        
        for (const char& ch: s) {
            if (isdigit(ch)) {
                digits.push_back(ch);
            } else {
                alphas.push_back(ch);
            }
        }
        
        if (abs((int) size(digits) - (int) size(alphas)) > 1) {
            return "";
        }
        
        if (size(alphas) > size(digits)) {
            for (int i = 0, j = 0; i < size(alphas); i++, j += 2) {
                ans[j] = alphas[i];
            }
            
            for (int i = 0, j = 1; i < size(digits); i++, j += 2) {
                ans[j] = digits[i];
            }
        } else {
            for (int i = 0, j = 0; i < size(digits); i++, j += 2) {
                ans[j] = digits[i];
            }
            
            for (int i = 0, j = 1; i < size(alphas); i++, j += 2) {
                ans[j] = alphas[i];
            }
        }
        
        return ans;
    }
};