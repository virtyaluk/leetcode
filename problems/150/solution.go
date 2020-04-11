package main
import "strconv"

func evalRPN(tokens []string) int {
    stack := []int{}
    
    for _, token := range tokens {
        switch token {
        case "+", "-", "*", "/":
            a, b, c := stack[len(stack) - 2], stack[len(stack) - 1], 0
            stack = stack[0: len(stack) - 2]
            
            if token == "+" {
                c = a + b
            } else if token == "*" {
                c = a * b
            } else if token == "-" {
                c = a - b
            } else {
                c = a / b
            }
            
            stack = append(stack, c)
            
        default:
            val, _ := strconv.Atoi(token)
            
            stack = append(stack, val)
        }
    }
    
    return stack[0]
}