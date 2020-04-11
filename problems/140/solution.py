class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wdset = set()
        
        for word in wordDict:
            wdset |= set(word)
        
        if not set(s).issubset(wdset):
            return []
        
        m, ans = defaultdict(set), []
        
        for word in wordDict:
            m[len(word)].add(word)
            
        def dfs(pos, ar):
            if pos == len(s):
                ans.append(' '.join(ar))
                return
        
            for k in m:
                if s[pos:pos + k] in m[k]:
                    dfs(pos + k, ar + [s[pos:pos + k]])
        
        dfs(0, [])

        return ans