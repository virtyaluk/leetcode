package main
func findOrder(numCourses int, prerequisites [][]int) []int {
    graph, cycle, ans, colors := map[int][]int{}, false, []int{}, make([]int, numCourses)
    
    for _, preq := range prerequisites {
        u, v := preq[0], preq[1]
        graph[v] = append(graph[v], u)
    }
    
    for i := 0; i < numCourses; i++ {
        if colors[i] == 0 {
            dfs(graph, i, &cycle, &ans, colors)
        }
    }
    
    if cycle {
        return []int{}
    }
    
    return reverse(ans)
}

func dfs(graph map[int][]int, i int, cycle *bool, ans *[]int, colors []int) {
        if *cycle {
            return
        }
        
        colors[i] = 1
        
        for _, j := range graph[i] {
            if colors[j] == 1 {
                *cycle = true
                return
            } else if colors[j] == 0 {
                dfs(graph, j, cycle, ans, colors)
            }
        }
        
        colors[i] = 2
        *ans = append(*ans, i)
    }

func reverse(ar []int) []int {
    lo, hi := 0, len(ar) - 1
    
    for lo < hi {
        ar[lo], ar[hi] = ar[hi], ar[lo]
        lo++
        hi--
    }
    
    return ar
}