package main
type TrieNode struct {
    Children map[byte]*TrieNode
    EndOfWord bool
}

type Trie struct {
    root *TrieNode
}

func NewTrieNode() *TrieNode {
    return &TrieNode{
        make(map[byte]*TrieNode),
            false,
    }
}

func NewTrie() *Trie {
    return &Trie{
        NewTrieNode(),
    }
}

func (this *Trie) Insert(word string) {
    cur := this.root
    
    for i := len(word) - 1; i >= 0; i-- {
        ch := word[i]
        
        if _, ok := cur.Children[ch]; !ok {
            cur.Children[ch] = NewTrieNode()
        }
        
        cur = cur.Children[ch]
    }
    
    cur.EndOfWord = true
}

func (this *Trie) SumPathsLen() int {
    type pair struct {
        node *TrieNode
        len int
    }
    
    ans, q := 0, []pair{pair{this.root, 0}}
    
    for len(q) > 0 {
        nq := []pair{}
        
            for _, np := range q {
                np.len++

                if len(np.node.Children) == 0 {
                    ans += np.len
                    continue
                }
                
                for _, next := range np.node.Children {
                    nq = append(nq, pair{next, np.len});
                }
            }
        
        q = nq
    }
    

    
    return ans
}

func minimumLengthEncoding(words []string) int {
    trie := NewTrie()
    
    for _, word := range words {
        trie.Insert(word)
    }
    
    return trie.SumPathsLen()
}