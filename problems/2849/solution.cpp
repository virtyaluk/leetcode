class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int w = abs(sx - fx),
            h = abs(sy - fy);
        
        if (not w and not h and t == 1) {
            return false;
        }
        
        return max(w, h) <= t;
    }
};