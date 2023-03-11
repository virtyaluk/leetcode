class Solution {
public:
    int minSwaps(string s) {
        int n = size(s),
            ones = count(begin(s), end(s), '1'),
            zeros = n - ones,
            count1 = 0,
            count2 = 0;
        
        if (abs(zeros - ones) > 1) {
            return -1;
        }
        
        for (int i = 0; i < n; i += 2) {
            count1 += s[i] != '0';
            count2 += s[i] != '1';
        }
        
        if (ones == zeros) {
            return min(count1, count2);
        }
        
        return ones > zeros ? count2 : count1;
    }
};