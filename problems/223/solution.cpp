class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rectA = (ax2 - ax1) * (ay2 - ay1),
            rectB = (bx2 - bx1) * (by2 - by1),
            overlap = 0,
            left = max(ax1, bx1),
            right = min(ax2, bx2),
            top = min(ay2, by2),
            bottom = max(ay1, by1);
        
        if (right > left and top > bottom) {
            overlap = (right - left) * (top - bottom);
        }
        
        return rectA + rectB - overlap;
    }
};