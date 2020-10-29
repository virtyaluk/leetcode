package main
func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
    p := [][]int{}
    
    p = append(p, p1, p2, p3, p4)
    
    sort.Slice(p, func(i, j int) bool {
        l1, l2 := p[i], p[j]
        
        if l1[0] == l2[0] {
            return l1[1] < l2[1]
        }
        
        return l1[0] < l2[0]
    })
    
    return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) && dist(p[1], p[3]) == dist(p[3], p[2]) && dist(p[3], p[2]) == dist(p[2], p[0]) && dist(p[0],p[3]) == dist(p[1],p[2])
}

func dist(p1, p2 []int) int {
    return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
}