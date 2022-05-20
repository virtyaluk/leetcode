package main
type CustomStack struct {
    list []int
    size int
    index int
}


func Constructor(maxSize int) CustomStack {
    return CustomStack{make([]int, maxSize), maxSize, -1}
}


func (this *CustomStack) Push(x int)  {
    if this.index < this.size - 1 {
        this.index++
        this.list[this.index] = x
    }
}


func (this *CustomStack) Pop() int {
    if this.index >= 0 {
        el := this.list[this.index]
        this.list[this.index], this.index = -1, this.index - 1
        
        return el
    }
    
    return -1
}


func (this *CustomStack) Increment(k int, val int)  {
    j := 0
    
    for j <= this.index && k > 0 {
        this.list[j] += val
        j++
        k--
    }
}


/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */