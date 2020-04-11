package main
func reverseBits(num uint32) uint32 {
    ans := uint32(0)
    
    for i := 31; i >= 0; i-- {
        if num & (1 << i) != 0 {
            ans ^= 1 << (31 - i)
        }
    }
    
    return ans
}