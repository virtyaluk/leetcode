package main
func judgeCircle(moves string) bool {
    x, y := 0, 0

    for _, char := range moves {
        switch char {
	    case 'U':
	        y++
	
        case 'D':
	        y--
	
        case 'L':
	        x--
	
        case 'R':
	        x++
        }
    }

	return x|y == 0
}