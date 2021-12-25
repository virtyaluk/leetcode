package main
type cb struct {
    worker, bike int
}

func assignBikes(workers [][]int, bikes [][]int) []int {
    ans, pairs, bikesUsed := make([]int, len(workers)), make([][]cb, 2001), make([]bool, len(bikes))
    
    for i := range ans {
        ans[i] = -1
    }
    
    for i := 0; i < len(workers); i++ {
        for j := 0; j < len(bikes); j++ {
            curDist := dist(workers[i], bikes[j])
            pairs[curDist] = append(pairs[curDist], cb{i, j})
        }
    }
    
    for _, bucket := range pairs {
        for _, pair := range bucket {
            if ans[pair.worker] == -1 && !bikesUsed[pair.bike] {
                ans[pair.worker] = pair.bike
                bikesUsed[pair.bike] = true
            }
        }
    }
    
    return ans
}

func dist(a, b []int) int {
    return abs(a[0] - b[0]) + abs(a[1] - b[1])
}

func abs(a int) int {
    if a > 0 {
        return a
    }
    
    return a * -1
}