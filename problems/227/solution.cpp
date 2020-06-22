class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        int ans = 0, lastNum = 0, curNum = 0;
        char lastOp = '+';
        
        for (int i = 0; i < size(s); i++) {
            if (isblank(s[i])) {
                continue;
            } else if (isdigit(s[i])) {
                curNum = curNum * 10 + (s[i] - '0');
            } else {
                if (lastOp == '+' or lastOp == '-') {
                    ans += lastNum;
                    lastNum = lastOp == '+' ? curNum : -curNum;
                } else if (lastOp == '*') {
                    lastNum *= curNum;
                } else if (lastOp == '/') {
                    lastNum /= curNum;
                }
                
                lastOp = s[i];
                curNum = 0;
            }
        }
        
        return ans + lastNum;
    }
};