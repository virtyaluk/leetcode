package main
type MapSum struct {
    m map[string]int
}


/** Initialize your data structure here. */
func Constructor() MapSum {
    return MapSum{make(map[string]int)}
}


func (this *MapSum) Insert(key string, val int)  {
    this.m[key] = val
}


func (this *MapSum) Sum(prefix string) int {
    ans := 0
    
    for key := range this.m {
        if strings.HasPrefix(key, prefix) {
            ans += this.m[key]
        }
    }
    
    return ans
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */