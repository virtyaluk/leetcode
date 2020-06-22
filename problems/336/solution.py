class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ans, m = [], {word: i for i, word in enumerate(words)}
            
        for idx, word in enumerate(words):
            reversedWord = word[::-1]
            
            if reversedWord in m and m[reversedWord] != idx:
                ans.append([idx, m[reversedWord]])
            
            for suff in self.getValidSuffixes(word):
                reversedSuf = suff[::-1]
                
                if reversedSuf in m and m[reversedSuf] != idx:
                    ans.append([m[reversedSuf], idx])
            
            for pref in self.getValidPrefixes(word):
                reversedPref = pref[::-1]
                
                if reversedPref in m and m[reversedPref] != idx:
                    ans.append([idx, m[reversedPref]])
        
        return ans
    
    def getValidSuffixes(self, word: str) -> List[str]:
        for i in range(len(word)):
            if word[:i + 1] == word[:i + 1][::-1]:
                yield word[i + 1:]
    
    def getValidPrefixes(self, word: str) -> List[str]:
        for i in range(len(word)):
            if word[i:] == word[i:][::-1]: 
                yield word[:i]