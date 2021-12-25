package main
func twoCitySchedCost(costs [][]int) int {
    sort.Slice(costs, func (i, j int) bool {
        a, b := costs[i][0] - costs[i][1], costs[j][0] - costs[j][1]
        
        return a < b
    })
    
    // fmt.Println(costs)
    
    ans := 0
    
    for i := 0; i < len(costs) / 2; i++ {
        ans += costs[i][0]
    }
    
    for i := len(costs) / 2; i < len(costs); i++ {
        ans += costs[i][1]
    }
    
    return ans
}