class Solution:
    def checkInclusion1(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1sorted, s1len = "".join(sorted(s1)), len(s1)
        
        for i in range(len(s2) - s1len):
            s2sub = "".join(sorted(s2[i:i + s1len]))
            
            if s2sub == s1sorted:
                return True
            
        return False
    
    def matches(self, m1, m2):
        for k in m1.keys():
            if m1[k] - m2.get(k, 0) != 0:
                return False

        return True
    
    def checkInclusion2(self, s1, s2):
        if len(s1) > len(s2):
            return False

        s1map = collections.Counter(s1)
        
        for i in range(len(s2) - len(s1)):
            s2map = collections.Counter(s2[i:i+len(s1)])
            
            if self.matches(s1map, s2map):
                return True
        
        return False

    def matches2(self, ar1, ar2):
        for i in range(len(ar1)):
            if ar1[i] != ar2[i]:
                return False
        
        return True

    def checkInclusion3(self, s1, s2):
        if len(s1) > len(s2):
            return False

        s1ar = [0] * 26
        
        for i in range(len(s1)):
            s1ar[ord(s1[i]) - ord('a')] += 1
        
        for i in range(len(s2) - len(s1)):
            s2ar = [0] * 26
            
            for j in range(i, i + len(s1)):
                s2ar[ord(s2[j]) - ord('a')] += 1
            
            print(s2ar)
            
            if self.matches2(s1ar, s2ar):
                return True
        
        return False

    def checkInclusion(self, s1, s2):
        if len(s1) > len(s2):
            return False
        
        s1ar = [0] * 26
        s2ar = [0] * 26
        
        for i in range(len(s1)):
            s1ar[ord(s1[i]) - ord('a')] += 1
            s2ar[ord(s2[i]) - ord('a')] += 1
        
        for i in range(len(s2) - len(s1)):
            if self.matches2(s1ar, s2ar):
                return True
            
            s2ar[ord(s2[i]) - ord('a')] -= 1
            s2ar[ord(s2[i + len(s1)]) - ord('a')] += 1
        
        return self.matches2(s1ar, s2ar)
        
        