class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int curA = 0,
            curB = 0,
            curC = 0,
            total = a + b + c;
        
        for (int i = 0; i < total; i++) {
            if ((a >= b and a >= c and curA != 2) or (a > 0 and (curB == 2 or curC == 2))) {
                ans.push_back('a');
                a--;
                curA++;
                curB = 0;
                curC = 0;
            } else if ((b >= a and b >= c and curB != 2) or (b > 0 and (curC == 2 or curA == 2))) {
                ans.push_back('b');
                b--;
                curB++;
                curA = 0;
                curC = 0;
            } else if ((c >= a and c >= b and curC != 2) or (c > 0 and (curA == 2 or curB == 2))) {
                ans.push_back('c');
                c--;
                curC++;
                curA = 0;
                curB = 0;
            }
        }
        
        return ans;
    }
};