package main
import "math/bits"

func bitwiseComplement(N int) int {
    if N == 0 {
        return 1
    }
    
    k := (1 << (32 - bits.LeadingZeros32(uint32(N)))) - 1
    
    return ^N & k
}

func countZeros(x int) int {
    n, y := 32, x >> 16
    
    if y != 0 {
        n = n - 16
        x = y
    }
  
    y = x >> 8
    
    if y != 0 {
        n = n - 8
        x = y
    }
  
    y = x >> 4
    
    if y != 0 {
        n = n - 4
        x = y
    }
  
    y = x >> 2
    
    if y != 0 {
        n = n - 2
        x = y
    }
  
    y = x >> 1
    
    if y != 0 {
        return n - 2
    }
    
    return n - x
}