package main
func canReach(arr []int, start int) bool {
    if len(arr) == 0 || start > len(arr) - 1 {
        return false
    }
    
    if arr[start] == 0 {
        return true
    }
    
    ans := false
    
    dfs(arr, start, make([]bool, len(arr)), &ans)
    
    return ans
}

func dfs(arr []int, i int, seen []bool, ans *bool) {
    if  i < 0 || i >= len(arr) || seen[i] || *ans {
        return
    }
    
    if arr[i] == 0 {
        *ans = true

        return
    }
    
    seen[i] = true
    
    dfs(arr, i + arr[i], seen, ans)
    dfs(arr, i - arr[i], seen, ans)
    
    seen[i] = false
}