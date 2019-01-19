/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let l = 0;
    let h = height.length - 1;
    let maxArea = 0;
    
    while (l < h) {
        maxArea = Math.max(maxArea, Math.min(height[l], height[h]) * (h - l));
        
        if (height[l] < height[h]) {
            l++;
        } else {
            h--;
        }
    }
    
    return maxArea;
};