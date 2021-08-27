package main
func possibleBipartition(N int, dislikes [][]int) bool {
    graph, colors := make([][]int, N + 1), make(map[int]int)
    
    for _, edge := range dislikes {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }
    
    for node := 1; node <= N; node++ {
        if !has(colors, node) && !bfs(graph, node, colors) {
            return false
        }
    }
    
    return true
}

func bfs(graph [][]int, node int, colors map[int]int) bool {
    q := []int{node}
    colors[node] = 1
    
    for len(q) > 0 {
        cur := q[0]
        q = q[1:]
        
        for _, adj := range graph[cur] {
            if !has(colors, adj) {
                q = append(q, adj)
                colors[adj] = colors[cur] ^ 1
            } else if colors[cur] == colors[adj] {
                return false
            }
        }
    }
    
    return true
}

func has(m map[int]int, n int) bool {
    _, ok := m[n]
    
    return ok
}