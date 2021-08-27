class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums)
    
        return nums
    
    def mergeSort(self, nums):
        if len(nums) > 1:
            mid = len(nums) // 2
            l = nums[:mid]
            r = nums[mid:]
            
            self.mergeSort(l)
            self.mergeSort(r)
            
            i, j, k = 0, 0, 0
            
            while i < len(l) and j < len(r):
                if l[i] < r[j]:
                    nums[k] = l[i]
                    i += 1
                else:
                    nums[k] = r[j]
                    j += 1

                k += 1
        
            while i < len(l):
                nums[k] = l[i]
                k += 1
                i += 1

            while j < len(r):
                nums[k] = r[j]
                k += 1
                j += 1
