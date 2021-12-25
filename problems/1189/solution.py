class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        m = dict()
        
        for ch in text:
            if ch not in m:
                m[ch] = 0
            
            m[ch] += 1
        
        if 'l' in m:
            m['l'] = m['l'] // 2
            
        if 'o' in m:
            m['o'] = m['o'] // 2
        
        return min([m[ch] if ch in m else 0 for ch in 'balloon'])