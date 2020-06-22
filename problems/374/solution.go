package main
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    lo, hi := 1, n
    
    for lo <= hi {
        mid := lo + (hi - lo) / 2
        hint := guess(mid)
        
        if hint == 0 {
            return mid
        } else if hint == 1 {
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    
    return -1
}