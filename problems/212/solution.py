class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        ans, trie = [], self.build_trie(words)
        
        for x in range(len(board)):
            for y in range(len(board[0])):
                self.dfs(board, x, y, trie, ans)
        
        return ans
        
    def build_trie(self, words):
        trie = Trie()
        
        for word in words:
            node = trie
            
            for ch in word:
                chi = ord(ch) - ord('a')

                if not node.nodes[chi]:
                    node.nodes[chi] = Trie()
                
                node = node.nodes[chi]
            
            node.word = word
        
        return trie
    
    def dfs(self, grid, x, y, trie, ans):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == '$' or not trie.nodes[ord(grid[x][y]) - ord('a')]:
            return
        
        tmp = grid[x][y]
        trie = trie.nodes[ord(tmp) - ord('a')]
        
        if trie.word:
            ans.append(trie.word)
            trie.word = ''
        
        grid[x][y] = '$'
        
        self.dfs(grid, x - 1, y, trie, ans)
        self.dfs(grid, x + 1, y, trie, ans)
        self.dfs(grid, x, y - 1, trie, ans)
        self.dfs(grid, x, y + 1, trie, ans)
        
        grid[x][y] = tmp


class Trie:
    def __init__(self):
        self.nodes = [None] * 26
        self.word = ''