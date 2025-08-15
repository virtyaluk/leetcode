class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z - x),
            b = abs(z - y);
        
        if (a == b) {
            return 0;
        }

        return a < b ? 1 : 2;
    }
};