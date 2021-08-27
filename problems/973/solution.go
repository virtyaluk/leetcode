package main
func kClosest(points [][]int, K int) [][]int {
    sort.Slice(points, func(i, j int) bool {
        p1, p2 := points[i][0] * points[i][0] + points[i][1] * points[i][1], points[j][0] * points[j][0] + points[j][1] * points[j][1]
        
        return p1 < p2
    });
    
    return points[:K]
}