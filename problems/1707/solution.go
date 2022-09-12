package main
type Trie struct {
    z, o *Trie
}

func (this *Trie) insert(k, num int) {
    if k < 0 {
        return
    }
    
    if ((num >> k) & 1) == 1 {
        if this.o == nil {
            this.o = &Trie{}
        }
        
        this.o.insert(k - 1, num)
    } else {
        if this.z == nil {
            this.z = &Trie{}
        }
        
        this.z.insert(k - 1, num)
    }
}

func (this *Trie) query(k, num int) int {
    ans := 0
    
    if k < 0 {
        return ans
    }
    
    if ((num >> k) & 1) == 1 {
        if this.z != nil {
            ans = pow(2, k) + this.z.query(k - 1, num)
        } else {
            ans = this.o.query(k - 1, num)
        }
    } else {
        if this.o != nil {
            ans = pow(2, k) + this.o.query(k - 1, num)
        } else {
            ans = this.z.query(k - 1, num)
        }
    }
    
    return ans
}

func pow(a, b int) int {
    return int(math.Pow(float64(a), float64(b)))
}

func maximizeXor(nums []int, queries [][]int) []int {
    ans, trie := make([]int, len(queries)), &Trie{}
    
    for i := 0; i < len(queries); i++ {
        queries[i] = append(queries[i], i)
    }
    
    sort.Ints(nums)
    sort.Slice(queries, func (i, j int) bool {
        return queries[i][1] < queries[j][1]
    })
    
    for i, j := 0, 0; i < len(queries); i++ {
        xi, mi, idx := queries[i][0], queries[i][1], queries[i][2]
        
        for j < len(nums) && nums[j] <= mi {
            trie.insert(31, nums[j])
            j++
        }
        
        if j > 0 {
            ans[idx] = trie.query(31, xi)
        } else {
            ans[idx] = -1
        }
    }
    
    return ans
}