package main
func eraseOverlapIntervals(intervals [][]int) int {
    if len(intervals) == 0 {
        return 0
    }
    
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][1] - intervals[j][1] < 0
    })
    
    end, count := intervals[0][1], 1
    
    for i := 1; i < len(intervals); i++ {
        if intervals[i][0] >= end {
            end = intervals[i][1]
            count++
        }
    }
    
    return len(intervals) - count
}