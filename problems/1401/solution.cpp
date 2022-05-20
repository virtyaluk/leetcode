class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        function<bool(int, int)> contains = [&](int x, int y) {
            return pow(x - x_center, 2) + pow(y - y_center, 2) <= pow(radius, 2);
        };
        
        // check circle center is inside a rectangle
        if (x_center >= x1 and x_center <= x2 and y_center >= y1 and y_center <= y2) {
            return true;
        }
        
        // check horizontal points
        for (int x = x1; x <= x2; x++) {
            if (contains(x, y1) or contains(x, y2)) {
                return true;
            }
        }
        
        // check vertical points
        for (int y = y1; y <= y2; y++) {
            if (contains(x1, y) or contains(x2, y)) {
                return true;
            }
        }
        
        return false;
    }
};