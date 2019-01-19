/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var p1 = nums1.length,
        p2 = nums2.length,
        n = p1+p2;

    if (n == 0) {
        n--;
    }
    
    var med = 0;
    p1--;
    p2--;

    while (0 < n) {
        if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
            med = nums1[p1--];
        } else {
            med = nums2[p2--];
        }
        
        n -= 2;
    }
    
    if (0 == n) {
      if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
        med = med+nums1[p1];
      } else {
        med = med+nums2[p2];
      }
        
      med /= 2;
    }
    
    return med;
};