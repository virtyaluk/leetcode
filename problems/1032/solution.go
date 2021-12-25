package main
type TrieNode struct {
    children map[byte]*TrieNode
    word bool
}

type StreamChecker struct {
    trie *TrieNode
    stream []byte
}


func Constructor(words []string) StreamChecker {
    stream := []byte{}
    trie := &TrieNode{}
    
    for _, word := range words {
        node := trie

        for i := len(word) - 1; i >= 0; i-- {
            char := word[i]

            if node.children == nil {
                node.children = make(map[byte]*TrieNode)
            }
            
            if node.children[char] == nil {
                node.children[char] = &TrieNode{}
            }
            
            node = node.children[char]
        }
        
        node.word = true
    }
    
    return StreamChecker{trie, stream}
}


func (this *StreamChecker) Query(letter byte) bool {
    this.stream = append([]byte{letter}, this.stream...)
    
    node := this.trie
    
    for _, char := range this.stream {
        if node.word {
            return true
        }
        
        if node.children[char] == nil {
            return false
        }
        
        node = node.children[char]
    }
    
    return node.word
}


/**
 * Your StreamChecker object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.Query(letter);
 */