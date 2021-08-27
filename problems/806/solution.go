package main
func numberOfLines(widths []int, S string) []int {
    res := make([]int, 2)
    res[0] = 1
    
    for _, char := range S {
        charWidth := widths[char - 97]

	    if res[1] + charWidth > 100 {
		    res[0]++
		    res[1] = charWidth
	    } else {
		    res[1] += charWidth
	    }
    }
    
    return res
}