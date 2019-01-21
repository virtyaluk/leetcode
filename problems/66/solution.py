class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        overhead = 0
        i = len(digits)
        
        while i > 0:
            i -= 1
            sum = digits[i] + overhead
            
            if i == len(digits) -1:
                sum += 1
            
            if sum >= 10:
                sum -= 10
                overhead = 1
            else:
                overhead = 0
            
            digits[i] = sum
            
            if not overhead:
                break
        
        if overhead:
            digits.insert(0, 1)
        
        return digits