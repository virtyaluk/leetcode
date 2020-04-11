class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        ans, s, q = 1, set(wordList), deque([beginWord])
        
        while q:
            qlen = len(q)
            
            for _ in range(qlen):
                word = q.popleft()
                
                for i in range(len(word)):
                    for next in [word for word in [word[:i] + ch + word[i + 1:] for ch in string.ascii_letters[:26]] if word in s]:
                        if next == endWord:
                            return ans + 1
                            
                        q.append(next)
                        s.remove(next)
            
            ans += 1
        
        return 0