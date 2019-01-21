class Solution:
    def addBinary(self, a: str, b: str) -> str:
        overhead = False
        i = len(a)
        j = len(b)
        res = ''
        
        while i > 0 or j > 0:
            i -= 1
            j -= 1
            ach = a[i] if i >= 0 else '0'
            bch = b[j] if j >= 0 else '0'
            ap = None
            
            if ach == '1' and ach == bch:
                ap = '1' if overhead else '0'
                overhead = True
            elif ach == '0' and ach == bch:
                ap = '1' if overhead else '0'
                overhead = False
            else:
                ap = ach if ach == '1' else bch
                
                if overhead:
                    ap = '0'
            
            res = ap + res
        
        if overhead:
            res = '1' + res
        
        return res