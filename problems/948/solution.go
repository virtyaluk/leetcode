package main
func bagOfTokensScore(tokens []int, P int) int {
    score, lo, hi := 0, 0, len(tokens) - 1
    
    sort.Ints(tokens);
    
    for lo <= hi {
        if tokens[lo] <= P {
            score++
            P -= tokens[lo]
            lo++
        } else if score > 0 {
            if lo == hi {
                break
            }
            
            score--
            P += tokens[hi]
            hi--
        } else {
            break
        }
    }
    
    return score
}