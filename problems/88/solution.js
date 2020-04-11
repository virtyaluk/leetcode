/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let pos = nums1.length - 1;
    m--;
    n--
    
    while (~m && ~n) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    
    while (~m) {
        nums1[pos--] = nums1[m--];
    }
    
    while (~n) {
        nums1[pos--] = nums2[n--]
    }
};