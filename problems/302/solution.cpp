class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int top = x, left = y, bottom = x, right = y;
        
        for (x = 0; x < size(image); x++) {
            for (y = 0; y < size(image[x]); y++) {
                if (image[x][y] == '1') {
                    top = min(top, x);
                    left = min(left, y);
                    bottom = max(bottom, x + 1);
                    right = max(right, y + 1);
                }
            }
        }
        
        return (bottom - top) * (right - left);
    }
};