package main
type Solution struct {
    w []int
}


func Constructor(w []int) Solution {
    for i := 1; i < len(w); i++ {
        w[i] += w[i - 1]
    }
    
    return Solution{w}
}


func (this *Solution) PickIndex() int {
    target, lo, hi := rand.Intn(this.w[len(this.w) - 1]), 0, len(this.w) - 1
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        
        if this.w[mid] <= target {
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    
    return lo
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */