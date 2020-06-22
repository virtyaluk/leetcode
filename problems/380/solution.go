package main
type RandomizedSet struct {
    l []int
    m map[int]int
}


/** Initialize your data structure here. */
func Constructor() RandomizedSet {
    return RandomizedSet{[]int{}, map[int]int{}}
}


/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
    if _, ok := this.m[val]; ok {
        return false
    }
    
    this.l = append(this.l, val)
    this.m[val] = len(this.l) - 1
    
    return true
}


/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
    idx, ok := this.m[val]
    
    if !ok {
        return false
    }
    
    n, lastVal := len(this.l), this.l[len(this.l) - 1]
    
    this.l[idx], this.l[n - 1] = this.l[n - 1], this.l[idx]
    this.m[lastVal] = idx
    this.l = this.l[:n-1]
    delete(this.m, val)
    
    return true
}


/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
    n := int32(len(this.l))
    
    return this.l[rand.Int31n(n)]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */