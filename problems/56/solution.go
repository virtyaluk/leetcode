func merge(intervals [][]int) [][]int {
    ans := [][]int{}
    
    sort.Slice(intervals, func (i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })
    
    fmt.Println(intervals)
    
    for _, i := range intervals {
        if len(ans) == 0 || i[0] > ans[len(ans) - 1][1] {
            ans = append(ans, i)
        } else if i[1] > ans[len(ans) - 1][1] {
            ans[len(ans) - 1][1] = i[1]
        }
    }
    
    return ans
}