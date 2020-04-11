class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(list(filter(None, s.strip().split(' ')))[::-1])