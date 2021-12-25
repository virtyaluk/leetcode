class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        cc, l = Counter(chars), 0
        
        for word in words:
            wc = Counter(word)

            if all([True if ch in cc and wc[ch] <= cc[ch] else False for ch in wc.keys()]):
                l += len(word)
        
        return l