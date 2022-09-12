package main
const MOD = 1e9 + 7

func createSortedArray(instructions []int) int {
    ans, n, bit := 0, len(instructions), NewBIT(100002)
    
    for i := 0; i < n; i++ {
        lsum, rsum := bit.Query(instructions[i] - 1), i - bit.Query(instructions[i])
        ans += min(lsum, rsum)
        ans %= MOD
        bit.Update(instructions[i], 1)
    }
    
    return ans % MOD
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

type BIT struct {
	tree []int
	size int
}

func NewBIT(size int) *BIT {
	return &BIT{
		make([]int, size),
		size,
	}
}

func (this *BIT) Update(index, val int) {
	for ; index <= this.size; index += index & -index {
		this.tree[index] += val
	}
}

func (this *BIT) Query(index int) int {
	sum := 0

	for ; index > 0; index -= index & -index {
		sum += this.tree[index]
	}

	return sum
}