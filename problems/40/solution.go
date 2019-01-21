var ans [][]int

func combinationSum2(candidates []int, target int) [][]int {
    ans = [][]int{}
    
    sort.Ints(candidates)
    
    backtrack(candidates, target, 0, []int{})
    
    return ans
}

func backtrack(candidates []int, remain, idx int, cur []int) {
    if remain == 0 {
        ans = append(ans, cur)
        return
    }
    
    for i := idx; i < len(candidates); i++ {
        if i > idx && candidates[i] == candidates[i - 1] {
            continue
        }
        
        if remain - candidates[i] < 0 {
            break
        }
        
        ncur := append(cur, candidates[i])
        backtrack(candidates, remain - candidates[i], i + 1, ncur)
    }
}