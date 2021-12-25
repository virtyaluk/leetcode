class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        if not len(matrix) or not len(matrix[0]):
            return 0
        
        ans = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i and j and matrix[i][j]:
                    matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1
                
                ans += matrix[i][j]
        
        return ans