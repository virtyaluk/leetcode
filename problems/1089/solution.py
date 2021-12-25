class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        zeros = 0
        
        for v in arr:
            if not v:
                zeros += 1
        
        for i in range(len(arr) - 1, -1, -1):
            if not arr[i]:
                if zeros + i < len(arr):
                    arr[zeros + i] = 0
                
                if zeros - 1 + i < len(arr):
                    arr[zeros - 1 + i] = 0
                
                zeros -= 1
            elif zeros + i < len(arr):
                arr[zeros + i] = arr[i]
        