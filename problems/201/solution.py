class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        mxn = m ^ n
        r1 = self.countLeadingZeros(mxn) if mxn else 31
        
        return m & n & (2**31 - (2**31 >> r1))
        
    def countLeadingZeros(self, x): 
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
        