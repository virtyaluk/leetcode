class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest, ans = max(candies), [False] * len(candies)
        
        for i in range(len(candies)):
            if candies[i] + extraCandies >= greatest:
                ans[i] = True
        
        return ans