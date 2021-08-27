package main
type DisjointSetUnion struct {
    parent, size []int
}

func InitDisjoinSetUnion(size int) *DisjointSetUnion {
    parent, sizeAr := make([]int, size + 1), make([]int, size + 1)
    
    for i, _ := range parent {
        parent[i] = i
    }
    
    for i, _ := range sizeAr {
        sizeAr[i] = 1
    }
    
    return &DisjointSetUnion{parent, sizeAr}
}

func (this *DisjointSetUnion) Find(x int) int {
    if this.parent[x] != x {
        this.parent[x] = this.Find(this.parent[x])
    }
    
    return this.parent[x]
}

func (this *DisjointSetUnion) Union(x, y int) int {
    px, py := this.Find(x), this.Find(y)
    
    if px == py {
        return px
    }
    
    if this.size[px] > this.size[py] {
        px, py = py, px
    }
    
    this.parent[px] = py
    this.size[py] += this.size[px]
    
    return py
}

func largestComponentSize(A []int) int {
    dsu, groupCount, maxSize := InitDisjoinSetUnion(max(A...)), map[int]int{}, 0
    
    for _, a := range A {
        for factor := 2; factor < int(math.Sqrt(float64(a))) + 1; factor++ {
            if a % factor == 0 {
                dsu.Union(a, factor)
                dsu.Union(a, a / factor)
            }
        }
    }
    
    for _, a := range A {
        groupId := dsu.Find(a)
        groupCount[groupId]++
        maxSize = max(maxSize, groupCount[groupId])
    }
    
    return maxSize
}

func max(nums ...int) int {
    m := nums[0]
    
    for _, num := range nums {
        if num > m {
            m = num
        }
    }
    
    return m
}