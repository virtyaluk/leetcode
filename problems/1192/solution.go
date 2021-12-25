package main
func criticalConnections(n int, connections [][]int) [][]int {
    ans, graph, visited, ids, id := [][]int{}, map[int][]int{}, make([]bool, n), make([]int, n), 0
    
    for _, e := range connections {
        graph[e[0]] = append(graph[e[0]], e[1])
        graph[e[1]] = append(graph[e[1]], e[0])
    }
    
    for i := 0; i < n; i++ {
        if !visited[i] {
            dfs(i, -1, graph, visited, ids, &id, &ans)
        }
    }
    
    return ans
}

func dfs(at, parent int, graph map[int][]int, visited []bool, ids []int, id *int, ans *[][]int) {
    visited[at] = true
    ids[at] = *id
    *id++
    
    for _, to := range graph[at] {
        if !visited[to] {
            dfs(to, at, graph, visited, ids, id, ans)
        }
    }
    
    if parent != -1 {
        curId := ids[at]
        
        for _, to := range graph[at] {
            if to != parent && ids[to] <= ids[parent] {
                curId = min(curId, ids[to])
            }
        }
        
        ids[at] = curId
        
        if curId > ids[parent] {
            *ans = append(*ans, []int{parent, at})
        }
    }
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}