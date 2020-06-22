package main
import "math"

func isPerfectSquare(num int) bool {
    x := int(math.Round(math.Exp(math.Log(float64(num)) / 2)))
    
    return x *x == num
}