package main
type StockSpanner struct {
    idx int
    stack [][]int
}


func Constructor() StockSpanner {
    return StockSpanner{-1, [][]int{}}
}


func (this *StockSpanner) Next(price int) int {
    ans := 0
    
    this.idx++
    
    for len(this.stack) > 0 && this.stack[len(this.stack) - 1][1] <= price {
        this.stack = this.stack[:len(this.stack) - 1]
    }
    
    if len(this.stack) > 0 {
        ans = this.idx - this.stack[len(this.stack) - 1][0]
    } else {
        ans = this.idx + 1
    }
    
    this.stack = append(this.stack, []int{this.idx, price})
    
    return ans
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */