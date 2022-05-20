package main
type SubrectangleQueries struct {
    ar [][]int
}


func Constructor(rectangle [][]int) SubrectangleQueries {
    return SubrectangleQueries{rectangle}
}


func (this *SubrectangleQueries) UpdateSubrectangle(row1 int, col1 int, row2 int, col2 int, newValue int)  {
    for x := row1; x <= row2; x++ {
        for y := col1; y <= col2; y++ {
            this.ar[x][y] = newValue
        }
    }
}


func (this *SubrectangleQueries) GetValue(row int, col int) int {
    return this.ar[row][col]
}


/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * obj := Constructor(rectangle);
 * obj.UpdateSubrectangle(row1,col1,row2,col2,newValue);
 * param_2 := obj.GetValue(row,col);
 */