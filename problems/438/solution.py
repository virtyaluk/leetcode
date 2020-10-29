class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s:
            return []
        
        chCounter, ans = [0] * 26, []
        
        for ch in p:
            chCounter[ord(ch) - ord('a')] += 1
        
        left, right, count = 0, 0, len(p)
        
        while right < len(s):
            if chCounter[ord(s[right]) - ord('a')] >= 1:
                count -= 1
            
            chCounter[ord(s[right]) - ord('a')] -= 1
            right += 1
            
            if count == 0:
                ans.append(left)
            
            if right - left == len(p):
                if chCounter[ord(s[left]) - ord('a')] >= 0:
                    count += 1
                
                chCounter[ord(s[left]) - ord('a')] += 1
                left += 1
        
        return ans