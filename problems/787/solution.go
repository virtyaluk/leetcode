package main
const MaxInt = int(^uint(0) >> 1)

func findCheapestPrice(n int, flights [][]int, src int, dst int, K int) int {
    ans, graph := MaxInt, map[int][][]int{}
    
    for _, flight := range flights {
        s := flight[0]
        graph[s] = append(graph[s], []int{flight[1], flight[2]}) 
    }
    
    dfs(graph, src, dst, 0, K + 1, &ans)
    
    if ans == MaxInt {
        return -1
    }
    
    return ans
}

func dfs(graph map[int][][]int, src, dst, p, k int, ans *int) {
    if k < 0 {
        return
    }
    
    if src == dst {
        *ans = min(*ans, p)
        return
    }
    
    for _, flight := range graph[src] {
        if flight[1] + p > *ans {
            continue
        }
        
        dfs(graph, flight[0], dst, p + flight[1], k - 1, ans)
    }
}

func min(a, b int) int {
    if a < b { return a }
    return b
}