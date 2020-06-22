package main
func findItinerary(tickets [][]string) []string {
    graph, ans := map[string][]string{}, []string{}
    
    for _, ticket := range tickets {
        from, to := ticket[0], ticket[1]
        graph[from] = append(graph[from], to)
    }
    
    for _, tos := range graph {
        sort.Strings(tos)
        reverse(tos)
    }
    
    dfs(graph, &ans, "JFK")
    
    return reverse(ans)
}

func dfs(graph map[string][]string, ans *[]string, start string) {
    for len(graph[start]) > 0 {
        n := len(graph[start])
        next := graph[start][n - 1]
        graph[start] = graph[start][:n - 1]
        
        dfs(graph, ans, next)
    }
    
    *ans = append(*ans, start)
}

func reverse(ar []string) []string {
    lo, hi := 0, len(ar) - 1
    
    for lo < hi {
        ar[lo], ar[hi] = ar[hi], ar[lo]
        lo++
        hi--
    }
    
    return ar
}