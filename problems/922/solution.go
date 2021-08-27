package main
func sortArrayByParityII(A []int) []int {
    j := 1
    
    for i := 0; i < len(A); i += 2 {
        if odd(A[i]) {
            for odd(A[j]) {
                j += 2
            }
            
            A[i], A[j] = A[j], A[i]
        }
    }
    
    return A
}

func odd(num int) bool {
    return num % 2 == 1
}