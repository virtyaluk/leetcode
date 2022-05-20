class Solution:
    def numberOfSteps (self, num: int) -> int:
        steps = 0
        
        while num:
            steps += 1
            
            if num % 2:
                num -= 1
            else:
                num /= 2
        
        return steps