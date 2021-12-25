package main
type CombinationIterator struct {
    n int
    k int
    chars string
    nums []int
    hasNext bool
}


func Constructor(characters string, combinationLength int) CombinationIterator {
    nums := make([]int, combinationLength)
    
    for i, _ := range nums {
        nums[i] = i
    }
    
    return CombinationIterator{
        len(characters),
        combinationLength,
        characters,
        nums,
        true,
    }
}


func (this *CombinationIterator) Next() string {
    var builder strings.Builder
    
    for _, num := range this.nums {
        builder.WriteByte(this.chars[num])
    }
    
    j := this.k - 1
    
    for ; j >= 0 && this.nums[j] == this.n - this.k + j; j-- {}
    
    
    if j >= 0 {
        this.nums[j]++
        
        for i := j + 1; i < this.k; i++ {
            this.nums[i] = this.nums[j] + i - j
        }
    } else {
        this.hasNext = false
    }
    
    return builder.String()
}


func (this *CombinationIterator) HasNext() bool {
    return this.hasNext
}


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */