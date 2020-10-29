class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(map(lambda s: ''.join(reversed(s)), s.split(' ')))