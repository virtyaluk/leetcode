class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels, ans, cur = set('aeiou'), 0, 0
        
        for i, ch in enumerate(s):
            if ch in vowels:
                cur += 1
            
            if i >= k and s[i - k] in vowels:
                cur -= 1
            
            ans = max(ans, cur)
            
        return ans