class Solution:
    def defangIPaddr(self, address: str) -> str:
        ip = ''
        
        for char in address:
            if char == '.':
                ip += '[.]'
            else:
                ip += char
        
        return ip