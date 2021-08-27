package main
func hasGroupsSizeX(deck []int) bool {
    count := map[int]int{}
    
    for _, v := range deck {
        count[v]++
    }
    
    g := -1
    
    for _, v:= range count {
        if g == -1 {
            g = v
        } else {
            g = gcd(g, v)
        }
    }
    
    return g >= 2
}

func gcd (x, y int) int {
    if x == 0 {
        return y
    }
    
    return gcd(y % x, x)
}