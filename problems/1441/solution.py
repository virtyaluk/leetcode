class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        s = set(target)
        
        for i in range(1, n + 1):
            if i <= target[-1]:
                ans.append('Push')
                
                if i not in s:
                    ans.append('Pop')
        
        return ans