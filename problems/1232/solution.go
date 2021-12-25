package main
func checkStraightLine(coordinates [][]int) bool {
    if len(coordinates) <= 2 {
        return true
    }
    
    x1, y1, x2, y2 := float64(coordinates[0][0]), float64(coordinates[0][1]), float64(coordinates[1][0]), float64(coordinates[1][1])
    slope := (y2 - y1)/(x2 - x1)
    
    for i := range coordinates[2:] {
        x, y := float64(coordinates[i + 2][0]), float64(coordinates[i + 2][1])
        
        if y - y1 != slope * (x - x1) {
            return false
        }
    }
    
    return true
}