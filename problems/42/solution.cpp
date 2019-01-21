class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, lo = 0, hi = size(height) - 1, leftMax = 0, rightMax = 0;
        
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                leftMax = max(leftMax, height[lo]);
                ans += leftMax - height[lo];
                lo++;
            } else {
                rightMax = max(rightMax, height[hi]);
                ans += rightMax - height[hi];
                hi--;
            }
        }
        
        return ans;
    }
};