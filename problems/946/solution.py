class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        n, j, k = len(pushed), 0, 0
        
        for num in pushed:
            pushed[k] = num
            
            while j < n and k >= 0 and pushed[k] == popped[j]:
                j += 1
                k -= 1
            
            k += 1
        
        return j >= n