class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a',
            y = coordinates[1] - '0';
        
        if (x % 2 == 0) {
            if (y % 2 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if (y % 2 == 0) {
                return false;
            } else {
                return true;
            }
        }
        
        return true;
    }
};