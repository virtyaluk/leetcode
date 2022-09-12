class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        
        cnt1, cnt2 = [0] * 26, [0] * 26
        
        for ch in word1:
            cnt1[ord(ch) - ord('a')] += 1
        
        for ch in word2:
            cnt2[ord(ch) - ord('a')] += 1
            
        for i in range(26):
            if (cnt1[i] > 0 and cnt2[i] == 0) or (cnt1[i] == 0 and cnt2[i] > 0):
                return False
        
        cnt1.sort()
        cnt2.sort()
        
        for i in range(26):
            if cnt1[i] != cnt2[i]:
                return False
        
        return True