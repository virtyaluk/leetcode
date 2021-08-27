class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def build(s):
            skip = 0
            
            for ch in reversed(s):
                if ch == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield ch
        
        return tuple(build(S)) == tuple(build(T))
                