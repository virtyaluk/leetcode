package main
func repeatedNTimes(A []int) int {
    repeat := make(map[int]bool)

	for _, num := range A {
		if repeat[num] {
			return num
		}

		repeat[num] = true
	}

	return 0
}