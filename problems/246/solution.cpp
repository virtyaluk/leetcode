class Solution {
public:
    bool isStrobogrammatic(string num) {
        int lo = 0, hi = num.size() - 1;
        
        while (lo <= hi) {
            if (not (num[lo] == '6' and num[hi] == '9')
               and not (num[lo] == '9' and num[hi] == '6')
               and not (num[lo] == '0' and num[lo] == num[hi])
               and not (num[lo] == '1' and num[lo] == num[hi])
               and not (num[lo] == '8' and num[lo] == num[hi])) {
                return false;
            }
            
            lo++;
            hi--;
        }
        
        
        return true;
    }
};