class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans, ai, bi = [], 0, 0
        
        while ai < len(A) and bi < len(B):
            xs, xe = max(A[ai][0], B[bi][0]), min(A[ai][1], B[bi][1])
            
            if xs <= xe:
                ans.append([xs, xe])
            
            if A[ai][1] < B[bi][1]:
                ai += 1
            else:
                bi += 1
        
        return ans