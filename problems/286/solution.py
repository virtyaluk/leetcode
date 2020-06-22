EMPTY = 2147483647

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        rows = len(rooms)

        if not rows: return
        
        cols, q = len(rooms[0]), deque([])
        
        for i in range(rows):
            for j in range(cols):
                if rooms[i][j] == 0:
                    q.append((i, j))
        
        while q:
            i, j = q.popleft()
            
            for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ni, nj = i + x, j + y
                
                if rows > ni >= 0 and cols > nj >= 0 and rooms[ni][nj] == EMPTY:
                    rooms[ni][nj] = rooms[i][j] + 1
                    
                    q.append((ni, nj))
        