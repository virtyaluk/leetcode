class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rows = [(sum(mat[i]), i) for i in range(len(mat))]
        
        rows.sort(key=lambda x: x)
        
        return [r[1] for r in rows[:k]]