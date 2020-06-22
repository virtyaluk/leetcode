package main
func canAttendMeetings(intervals [][]int) bool {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })
    
    for i := 1; i < len(intervals); i++ {
        if intervals[i - 1][1] > intervals[i][0] {
            return false
        }
    }
    
    return true
}