class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return tuple(sorted(s)) == tuple(sorted(t))