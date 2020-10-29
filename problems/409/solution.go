package main
type BitSet int

func longestPalindrome(s string) int {
    if len(s) == 0 {
        return 0
    }
    
    bitset, ans := new(BitSet), 0
    
    for _, ch := range s {
        pos := 0
        
        if ch >= 'A' && ch <= 'Z' {
            pos = int(ch - 'A') + 26
        } else {
            pos = int(ch - 'a')
        }
        
        if bitset.Get(pos) {
            ans += 2
        }
        
        bitset.Flip(pos)
    }
    
    return min(ans + 1, len(s))
}

func (set *BitSet) Flip(k int) {
    *set ^= (1 << k)
}

func (set *BitSet) Get(k int) bool {
    return (*set >> k) & 1 == 1
}

func min(a, b int) int {
    if a < b { return a }
    return b
}