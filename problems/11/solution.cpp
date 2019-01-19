class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, lo = 0, hi = height.size() - 1;
        
        while (lo < hi) {
            ans = max(ans, min(height[lo], height[hi]) * (hi - lo));
            
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        
        return ans;
    }
};