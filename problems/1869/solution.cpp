class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0,
            zeros = 0;
        
        for (int i = 0, ones1 = 0, zeros1 = 0; i < size(s); i++) {
            if (s[i] == '1') {
                zeros1 = 0;
                ones1++;
            } else {
                ones1 = 0;
                zeros1++;
            }
            
            ones = max(ones, ones1);
            zeros = max(zeros, zeros1);
        }
        
        return ones > zeros;
    }
};