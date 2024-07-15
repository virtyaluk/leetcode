class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        snum, ans = str(num), 0
        
        for i in range(len(snum) - k + 1):
            x = int(snum[i:i+k])
            ans += 1 if x and num % x == 0 else 0
        
        return ans