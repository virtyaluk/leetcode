package main
var print = fmt.Println

func getRow(rowIndex int) []int {
    row := []int{1}
    
    for i := 1; i <= rowIndex; i++ {
        newRow := make([]int, i + 1)
        
        for j := 0; j < i + 1; j++ {
            if j == 0 || j == i {
                newRow[j] = 1
            } else {
                newRow[j] = row[j] + row[j - 1]
            }
        }

        row = newRow
    }
    
    return row
}