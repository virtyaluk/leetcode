func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    m, n, k, ans := len(nums1), len(nums2), 0, 0.0
    k = (m + n + 1) / 2
    ans = findKthSmall(nums1, nums2, 0, m - 1, 0, n - 1, k)
    
    if (m + n) % 2 == 0 {
        ans += findKthSmall(nums1, nums2, 0, m - 1, 0, n - 1, k + 1)
        ans *= 0.5
    }
    
    return ans
}

func findKthSmall(a, b []int, alo, ahi, blo, bhi, k int) float64 {
    if alo > ahi {
        return float64(b[blo + k - 1])
    }
    
    if blo > bhi {
        return float64(a[alo + k - 1])
    }
    
    amid, bmid := alo + (ahi - alo) / 2, blo + (bhi - blo) / 2
    
    if a[amid] <= b[bmid] {
        if k <= (amid - alo) + (bmid - blo) + 1 {
            return findKthSmall(a, b, alo, ahi, blo, bmid - 1, k)
        } else {
            return findKthSmall(a, b, amid + 1, ahi, blo, bhi, k - (amid - alo) - 1)
        }
    } else {
        if k <= (amid - alo) + (bmid - blo) + 1 {
            return findKthSmall(a, b, alo, amid - 1, blo, bhi, k)
        } else {
            return findKthSmall(a, b, alo, ahi, bmid + 1, bhi, k - (bmid - blo) - 1)
        }
    }
    
    return 0
}

/*

[3, 4, 6, 10, 12, 15, 19] 10
[10, 12, 14, 16, 18, 20] 14
a = 3
b = 2
k = 7


*/