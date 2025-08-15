class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0,
            rem = 10;

        while (true) {
            if (rem <= n) {
                n -= rem;
                rem--;
                turn++;
            } else {
                break;
            }
        }
        
        return turn % 2 == 0 ? false : true;
    }
};