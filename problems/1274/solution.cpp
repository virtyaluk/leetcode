/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return helper(sea, bottomLeft, topRight);
    }
    
    int helper(Sea& sea, vector<int> bottom, vector<int> top) {
        if (bottom[0] > top[0] or bottom[1] > top[1]) {
            return 0;
        }

        if (top[0] == bottom[0] and top[1] == bottom[1]) {
            return int(sea.hasShips(top, bottom));
        }

        if (not sea.hasShips(top, bottom)) {
            return 0;
        }

        int x0 = bottom[0], y0 = bottom[1],
            x1 = top[0], y1 = top[1],
            cx = (x0 + x1) / 2,
            cy = (y0 + y1) / 2;

        return helper(sea, bottom, {cx, cy}) +
            helper(sea, {cx + 1, cy + 1}, top) +
            helper(sea, {x0, cy + 1}, {cx, y1}) +
            helper(sea, {cx + 1, y0}, {x1, cy});
    }
};