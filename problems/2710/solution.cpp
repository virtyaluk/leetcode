class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = size(num) - 1;
        
        while (i >= 0 and num[i] == '0') {
            i--;
        }
        
        if (i < 0) {
            return "";
        }
        
        return num.substr(0, i + 1);
    }
};