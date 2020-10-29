package main
import "math/bits"

func findComplement(num int) int {
    if num == 0 {
        return 1
    }
    
    k := (1 << (32 - bits.LeadingZeros32(uint32(num)))) - 1
    
    return ^num & k
}