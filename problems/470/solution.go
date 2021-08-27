package main
func rand10() int {
    var row int
    var col int
    var idx int
    
    for true {
        row, col = rand7(), rand7()
        idx = col + (row - 1) * 7
        
        if !(idx > 40) {
            break
        }
    }
    
    return 1 + (idx - 1) % 10
}