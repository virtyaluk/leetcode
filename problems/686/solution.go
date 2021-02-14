package main
import "fmt"
import "strings"

func repeatedStringMatch(A string, B string) int {
    q := (len(B) - 1) / len(A) + 1
    
    fmt.Println(q)
    
    for i := 0; i < 2; i++ {
        if strings.Contains(strings.Repeat(A, q + i), B) {
            return q + i
        }
    }
    
    return -1
}