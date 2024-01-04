class Solution {
public:
    bool checkString(string s) {
        for (int i = 0, j = INT_MAX; i < size(s); i++) {
            if (s[i] == 'b') {
                j = min(j, i);
            } else if (i > j) {
                return false;
            }
        }
        
        return true;
    }
};