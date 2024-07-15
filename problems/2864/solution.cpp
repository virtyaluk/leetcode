class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = size(s),
            ones = count(begin(s), end(s), '1');
        
        return string(ones - 1, '1') + string(n - ones, '0') + "1";
    }
};