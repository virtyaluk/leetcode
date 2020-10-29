class Solution:
    def validIPAddress(self, IP: str) -> str:
        if IP.count('.') == 3:
            return self.validate_ipv4(IP)
        
        if IP.count(':') == 7:
            return self.validate_ipv6(IP)
        
        return 'Neither'
        
    def validate_ipv4(self, s):
        for num in s.split('.'):
            if len(num) == 0 or len(num) > 3:
                return 'Neither'
            
            if num[0] == '0' and len(num) != 1 or not num.isdigit() or int(num) > 255:
                return 'Neither'
        
        return 'IPv4'
    
    def validate_ipv6(self, s):
        hex = '0123456789abcdefABCDEF'
        for num in s.split(':'):
            if len(num) == 0 or len(num) > 4 or not all(ch in hex for ch in num):
                return 'Neither'
        
        return 'IPv6'