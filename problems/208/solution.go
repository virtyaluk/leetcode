package main
const R = 26

type Trie struct {
    links [R]*Trie
    isEnd bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie{}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    node := this
    
    for _, v := range word {
        if !node.containsKey(v) {
            node.put(v, &Trie{})
        }
        
        node = node.get(v)
    }
    
    node.isEnd = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    node := this.searchPrefix(word)
    
    return node != nil && node.isEnd
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    node := this.searchPrefix(prefix)
    
    return node != nil
}

func (this *Trie) containsKey(ch rune) bool {
    return this.links[ch - 'a'] != nil
}

func (this *Trie) get(ch rune) *Trie {
    return this.links[ch - 'a']
}

func (this *Trie) put(ch rune, t *Trie) {
    this.links[ch - 'a'] = t
}

func (this *Trie) searchPrefix(prefix string) *Trie {
    node := this
    
    for _, v := range prefix {
        if !node.containsKey(v) {
            return nil
        }
        
        node = node.get(v)
    }
    
    return node
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */