class Solution:
    def findComplement(self, num: int) -> int:
        if not num:
            return 1
        
        k = (1 << (32 - self.countZeros(num))) - 1
        
        return ~num & k
    
    def countZeros(self, x): 
        n = 32; 
        y = x >> 16; 
        
        if (y != 0): 
            n = n - 16; 
            x = y; 

        y = x >> 8; 
        
        if (y != 0): 
            n = n - 8; 
            x = y; 

        y = x >> 4;
        
        if (y != 0): 
            n = n - 4; 
            x = y; 

        y = x >> 2; 
        
        if (y != 0): 
            n = n - 2; 
            x = y; 

        y = x >> 1;
        
        if (y != 0): 
            return n - 2; 
        
        return n - x; 