package main
const MOD = 1000000007

func maxSum(a []int, b []int) int {
    i, j, sa, sb, m, n := 0, 0, 0, 0, len(a), len(b)
    
    for i < m || j < n {
        if i < m && (j == n || a[i] < b[j]) {
            sa += a[i]
            i++
        } else if j < n && (i == m || a[i] > b[j]) {
            sb += b[j]
            j++
        } else {
            sa = max(sa, sb) + a[i]
            sb = sa
            i++
            j++
        }
    }
    
    return max(sa, sb) % MOD
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}