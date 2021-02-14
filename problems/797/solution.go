package main
func allPathsSourceTarget(graph [][]int) [][]int {
    ans := [][]int{}
    
    dfs(graph, []int{0}, len(graph) - 1, &ans)
    
    return ans
}

func dfs(graph [][]int, path []int, target int, ans *[][]int) {
    last := path[len(path) - 1]
    
    if last == target {
        *ans = append(*ans, path)
        return
    }
    
    for _, next := range graph[last] {
        newPath := make([]int, len(path) + 1)
        copy(newPath, path)
        newPath[len(newPath) - 1] = next
        
        dfs(graph, newPath, target, ans)
    }
}