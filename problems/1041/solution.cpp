class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        
        for (int i = 0; i < instructions.size(); i++) {
            char ch = instructions[i];
            
            if (ch == 'G') {
                if (d == 0) {
                    x++;
                } else if (d == 1) {
                    y++;
                } else if (d == 2) {
                    x--;
                } else {
                    y--;
                }
            } else if (ch == 'L') {
                d = (d + 3) % 4;
            } else if (ch == 'R') {
                d = (d + 1) % 4;
            }
        }
        
        return (x == 0 && y == 0) || d != 0;
    }
};