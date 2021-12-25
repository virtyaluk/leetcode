package main
import "sort"

func minimumAbsDifference(arr []int) [][]int {
    sort.Ints(arr)
    res := [][]int{}
    
    minDiff := int(^uint(0) >> 1)
    
    for i := 0; i + 1 < len(arr); i++ {
        if arr[i + 1] - arr[i] < minDiff {
            minDiff = arr[i + 1] - arr[i]
        }
    }
    
    for i := 0; i + 1 < len(arr); i++ {
        if arr[i + 1] - arr[i] == minDiff {
            res = append(res, []int{arr[i], arr[i + 1]})
        }
    }
    
    return res
}