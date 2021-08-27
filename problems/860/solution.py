class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = 0
        
        for b in bills:
            if b == 5:
                five += 1
            elif b == 10:
                if not five:
                    return False
                
                ten += 1
                five -= 1
            elif b == 20:
                if ten and five:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        
        return True
                