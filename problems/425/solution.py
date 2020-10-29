class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        self.words = words
        self.n = len(words[0])
        self.buildPrefTable(self.words);
        
        ans, wordSquares = [], []
        
        for word in words:
            wordSquares = [word]
            
            self.backtrack(1, wordSquares, ans)
        
        return ans
    
    def buildPrefTable(self, words):
        self.prefTable = {}
        
        for word in words:
            for prefix in (word[:i] for i in range(1, len(word))):
                self.prefTable.setdefault(prefix, set()).add(word);
    
    def backtrack(self, step, wordSquares, ans):
        if step == self.n:
            ans.append(wordSquares[:])
            return
    
        prefix = ''.join([word[step] for word in wordSquares])
        
        for candidate in self.getWordsWithPrefix(prefix):
            wordSquares.append(candidate)
            self.backtrack(step + 1, wordSquares, ans)
            wordSquares.pop()
    
    def getWordsWithPrefix(self, prefix):
        if prefix in self.prefTable:
            return self.prefTable[prefix]
        else:
            return set([])