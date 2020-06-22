package main
func reverseString(s []byte)  {
    lo, hi := 0, len(s) - 1
    
    for lo < hi {
        s[lo], s[hi] = s[hi], s[lo]
        lo++
        hi--
    }
}