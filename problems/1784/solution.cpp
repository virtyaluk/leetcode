class Solution {
public:
    bool checkOnesSegment(string s) {
        int ones = count(begin(s), end(s), '1');
        
        for (int i = 0, cnt = 0; i < size(s); i++) {
            cnt += s[i] == '1';
            
            if (s[i] == '0' and ones > cnt) {
                return false;
            }
        }
        
        return true;
    }
};