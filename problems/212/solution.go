package main
func findWords(board [][]byte, words []string) []string {
    ans, trie := []string{}, buildTrie(words)
    
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            dfs(board, i, j, trie, &ans)
        }
    }
    
    return ans
}

type Trie struct {
    Nodes [26]*Trie
    Word string
}

func buildTrie(words []string) *Trie {
    trie := &Trie{}
    
    for _, word := range words {
        node := trie
        
        for _, ch := range word {
            chi := ch - 'a'
            
            if node.Nodes[chi] == nil {
                node.Nodes[chi] = &Trie{}
            }
            
            node = node.Nodes[chi]
        }
        
        node.Word = word
    }
    
    return trie
}

func dfs(grid [][]byte, x, y int, trie *Trie, ans *[]string) {
    if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) || grid[x][y] == '$' || trie.Nodes[grid[x][y] - 'a'] == nil {
        return
    }
    
    tmp := grid[x][y]
    trie = trie.Nodes[tmp - 'a']
    
    if len(trie.Word) > 0 {
        *ans = append(*ans, trie.Word)
        trie.Word = ""
    }
    
    grid[x][y] = '$'
    
    dfs(grid, x - 1, y, trie, ans)
    dfs(grid, x + 1, y, trie, ans)
    dfs(grid, x, y - 1, trie, ans)
    dfs(grid, x, y + 1, trie, ans)
    
    grid[x][y] = tmp
}