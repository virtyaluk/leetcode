class TrieNode:
    def __init__(self):
        self.count = 0
        self.children = {}

class Solution:
    def getAbbr(self, word, index = 0):
        if len(word) - index <= 3:
            return word
        
        return word[:index + 1] + str(len(word) - 2 - index) + word[-1]
    
    def insert(self, root, word):
        node = root
        
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            
            node = node.children.get(ch)
            node.count += 1
    
    def find(self, root, word):
        node = root
        
        for idx, ch in enumerate(word):
            node = node.children.get(ch)
            
            if node.count == 1:
                return idx
        
        return -1 # len(node) - 1
    
    def wordsAbbreviation(self, words: List[str]) -> List[str]:
        ans, groups = [None] * len(words), defaultdict(list)
        
        for idx, word in enumerate(words):
            groups[self.getAbbr(word)].append(idx)
        
        for abbr, indices in groups.items():
            if len(indices) == 1:
                ans[indices[0]] = abbr
            else:
                trie = TrieNode()
                
                for idx in indices:
                    self.insert(trie, words[idx])
                
                for idx in indices:
                    ans[idx] = self.getAbbr(words[idx], self.find(trie, words[idx]))
        
        return ans