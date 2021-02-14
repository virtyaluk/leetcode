package main
func calPoints(ops []string) int {
    output, points := 0, []int{}

	for _, str := range ops {
		switch str {
		case "+":
			lastTwo := points[len(points) - 2:]
			points = append(points, lastTwo[0] + lastTwo[1])
		case "D":
			points = append(points, 2 * points[len(points) - 1])
		
		case "C":
			points = points[0:len(points) - 1]

		default:
			givenPoints, _ := strconv.Atoi(str)
			points = append(points, givenPoints)
		}
	}
	
	for _, val := range points {
		output += val
	}

	return output
}