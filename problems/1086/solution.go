package main
func highFive(items [][]int) [][]int {
    m, ans := map[int][]int{}, [][]int{}
    
    for _, item := range items {
        m[item[0]] = append(m[item[0]], item[1])
    }
    
    for id, scores := range m {
        sort.Sort(sort.Reverse(sort.IntSlice(scores)))
        
        ans = append(ans, []int{id, avg(scores[:5]...)})
    }
    
    sort.Slice(ans, func(i, j int) bool {
        return ans[i][0] < ans[j][0]
    })
    
    return ans
}

func avg(items ...int) int {
    avg := 0
    
    for _, item := range items {
        avg += item
    }
    
    return avg / len(items)
}