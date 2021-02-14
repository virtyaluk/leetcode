package main
func toLowerCase(str string) string {
    arr := []byte(str)

	for i, char := range arr {
		if char >= 65 && char <= 90 {
			arr[i] += 32
		}
	}

	return string(arr)
}