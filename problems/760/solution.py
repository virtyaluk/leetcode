class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        m = defaultdict(set)
        
        for i in range(len(B)):
            m[B[i]].add(i)
        
        return [m[num].pop() for num in A]