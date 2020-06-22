class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.childs = {}
        self.isEnd = False
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self
        
        for v in word:
            ch = ord(v) - 97
            
            if ch not in node.childs:
                node.childs[ch] = Trie()
            
            node = node.childs[ch]
        
        node.isEnd = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self
        
        for v in word:
            ch = ord(v) - 97
            
            if ch not in node.childs:
                return False
            
            node = node.childs[ch]
            
        return node and node.isEnd

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self
        
        for v in prefix:
            ch = ord(v) - 97
            
            if ch not in node.childs:
                return False
            
            node = node.childs[ch]
        
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)