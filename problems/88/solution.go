package main
func merge(nums1 []int, m int, nums2 []int, n int)  {
    pos := len(nums1) - 1
    m--
    n--
    
    for m >= 0 && n >= 0 {
        if nums1[m] > nums2[n] {
            nums1[pos] = nums1[m]
            m--
        } else {
            nums1[pos] = nums2[n]
            n--
        }
        
        pos--
    }
    
    for m >= 0 {
        nums1[pos] = nums1[m]
        m--
        pos--
    }
    
    for n >= 0 {
        nums1[pos] = nums2[n]
        n--
        pos--
    }
}