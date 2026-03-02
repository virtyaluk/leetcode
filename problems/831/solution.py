class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            lo, hi = s.split('@')

            return f'{lo[0]}*****{lo[-1]}@{hi}'.lower()
        else:
            digits = ''

            for ch in s:
                if ch.isdigit():
                    digits += ch

            local = f'***-***-{digits[-4:]}'

            if len(digits) == 10:
                return local
            
            a = '*' * (len(digits) - 10)

            return f'+{a}-{local}'