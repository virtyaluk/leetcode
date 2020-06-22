class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        
        def bt(rem, comb, ns):
            if rem == 0 and len(comb) == k:
                ans.append(list(comb))
            elif rem < 0 or len(comb) == k:
                return
            for i in range(ns, 9):
                comb.append(i + 1)
                bt(rem - i - 1, comb, i + 1)
                comb.pop()
            

        bt(n, [], 0)
        return ans