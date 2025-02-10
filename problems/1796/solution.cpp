class Solution {
public:
    int secondHighest(string s) {
        bitset<11> bs;
        
        for (const char& ch: s) {
            if (isdigit(ch)) {
                bs[ch - '0'] = true;
            }
        }
        
        for (int i = 10, first = 0; i >= 0; i--) {
            if (not bs[i]) {
                continue;
            }
            
            if (first) {
                return i;
            }
            
            first = 1;
        }
        
        return -1;
    }
};