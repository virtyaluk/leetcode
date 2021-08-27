class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        score, lo, hi = 0, 0, len(tokens) - 1
        
        tokens.sort()
        
        while lo <= hi:
            if tokens[lo] <= P:
                P -= tokens[lo]
                score += 1
                lo += 1
            elif score > 0:
                if lo == hi:
                    break
                
                P += tokens[hi]
                score -= 1
                hi -= 1
            else:
                break
            
        return score