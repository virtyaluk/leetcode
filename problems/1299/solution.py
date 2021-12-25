class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        m = arr[-1]
        arr[-1] = -1
        i = len(arr) - 2
        
        while i >= 0:
            cm = arr[i]
            arr[i] = m
            m = max(m, cm)
            i -= 1
            
        return arr