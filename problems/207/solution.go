package main
func canFinish(numCourses int, prerequisites [][]int) bool {
    if len(prerequisites) == 0 {
        return true
    }
    
    graph, visited := make([][]int, numCourses), make([]int, numCourses)
    
    for _, prereq := range prerequisites {
        graph[prereq[1]] = append(graph[prereq[1]], prereq[0])
    }
    
    for i := 0; i < numCourses; i++ {
        if !dfs(graph, i, visited) {
            return false
        }
    }
    
    return true
}

func dfs(graph [][]int, course int, visited []int) bool {
    visited[course] = 1
    
    for _, nc := range graph[course] {
        if visited[nc] == 1 || !dfs(graph, nc, visited) {
            return false
        }
    }
    
    visited[course] = 0

    return true
}