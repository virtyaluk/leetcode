class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans = 0
        
        for word in words:
            consistent = [ch for ch in word if ch in allowed]
    
            if len(word) == len(consistent):
                ans += 1
        
        return ans;