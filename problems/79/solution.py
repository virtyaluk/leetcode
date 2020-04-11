class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        
        def dfs(i, x, y):
            if x < 0 or x >= m or y < 0 or y >= n or board[x][y] != word[i]:
                return False
            
            if i == len(word) - 1:
                return True
            
            tmp, board[x][y], i = board[x][y], '#', i + 1
            
            found = dfs(i, x + 1, y) or dfs(i, x - 1, y) or dfs(i, x, y + 1) or dfs(i, x, y - 1)
            
            board[x][y] = tmp
            
            return found
        
        for i in range(m):
            for j in range(n):
                if dfs(0, i, j):
                    return True
        
        return False