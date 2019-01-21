class Solution {
    public int trap(int[] height) {
        if (height.length == 0) {
            return 0;
        }
        
        int ans = 0, globalMax = 0, globalMaxIdx = 0;
        
        for (int i = 0; i < height.length; i++) {
            if (height[i] > globalMax) {
                globalMax = height[i];
                globalMaxIdx = i;
            }
        }
        
        for (int i = 0, curMax = 0; i <= globalMaxIdx; i++) {
            curMax = Math.max(curMax, height[i]);
            ans += curMax - height[i];
        }
        
        for (int i = height.length - 1, curMax = 0; i >= globalMaxIdx; i--) {
            curMax = Math.max(curMax, height[i]);
            ans += curMax - height[i];
        }
        
        return ans;
    }
}