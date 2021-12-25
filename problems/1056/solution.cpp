class Solution {
public:
    bool confusingNumber(int N) {
        const string s = to_string(N);
        string reverse(crbegin(s), crend(s));
        
        for (char& ch: reverse) {
            if (ch > '1' && ch < '6' || ch == '7') {
                return false;
            } else if (ch == '6') {
                ch = '9';
            } else if (ch == '9') {
                ch = '6';
            }
        }
        
        return s != reverse;
    }
};