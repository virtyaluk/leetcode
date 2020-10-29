class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        ans = []
        
        r1, r2, r3 = 'qQwWeErRtTyYuUiIoOpP', 'aAsSdDfFgGhHjJkKlL', 'zZxXcCvVbBnNmM'
        
        for word in words:
            if all([ch in r1 for ch in word]) or all([ch in r2 for ch in word]) or all([ch in r3 for ch in word]):
                ans.append(word)
        
        return ans