package main
func earliestAcq(logs [][]int, N int) int {
    ds := NewDisjointSet(N)
    sort.Slice(logs, func(i, j int) bool {
        return logs[i][0] < logs[j][0]
    })
    
    for i := 0; i < len(logs); i++ {
        ds.Union(logs[i][1], logs[i][2])
        
        if ds.Len() == 1 {
            return logs[i][0]
        }
    }
    
    return -1
}

type DisjointSet struct {
	size int
	rank, parent []int
}

func NewDisjointSet(n int) *DisjointSet {
	inst := &DisjointSet{
		n,
		make([]int, n),
		make([]int, n),
	}

	for i := 0; i < n; i++ {
		inst.parent[i] = i
	}

	return inst
}

func (this *DisjointSet) Len() int {
	return this.size
}

func (this *DisjointSet) Find(x int) int {
	if this.parent[x] != x {
		this.parent[x] = this.Find(this.parent[x])
	}

	return this.parent[x]
}

func (this *DisjointSet) Union(x, y int) {
	xSet, ySet := this.Find(x), this.Find(y)

	if xSet == ySet {
		return
	}

	if this.rank[xSet] < this.rank[ySet] {
		this.parent[xSet] = ySet
	} else if this.rank[xSet] > this.rank[ySet] {
		this.parent[ySet] = xSet
	} else {
		this.parent[ySet] = xSet
		this.rank[xSet] = this.rank[xSet] + 1
	}
    
    this.size--
}