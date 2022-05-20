class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        perms = product(['0', '1'], repeat=k)
        
        for perm in perms:
            p = ''.join(perm)
            
            if p not in s:
                return False
        
        return True