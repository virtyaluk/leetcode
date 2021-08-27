package main
func flipAndInvertImage(A [][]int) [][]int {
    for i, ar := range A {
		A[i] = doStuff(ar)
	}
	
	return A
}

func doStuff(ar []int) []int {
	len1 := len(ar)
	ar1 := make([]int, len1)
	for i := len1 - 1; i >= 0; i-- {
		if ar[i] == 0 {
			ar1[len1 - i -1] = 1
		} else {
			ar1[len1 - i -1] = 0
		}
		
	}
	
	return ar1
}