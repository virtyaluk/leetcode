package main
import "sort"

func arrayRankTransform(arr []int) []int {
    sorted, ranks, counter, resp := make([]int, len(arr)), make(map[int]int), 1, make([]int, len(arr))
    
    copy(sorted, arr)
    sort.Ints(sorted)
    
    for _, val := range sorted {
        if _, ok := ranks[val]; !ok {
            ranks[val] = counter
            counter++
        }
    }
    
    for idx, val := range arr {
        resp[idx] = ranks[val]
    }
    
    return resp
}