package main
func rotateString(A string, B string) bool {
    if A == B {
        return true
    }
    
    alen := len(A)
    
    if alen > 0 {
        for i := 0; i < alen; i++ {
            A = string(A[1:]) + string(A[0])

            if A == B {
                return true
            }
        }
    }
    
    return false
}