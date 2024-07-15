class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        if sentence[0] != sentence[-1]:
            return False
        
        words = sentence.split()
        
        for i in range(0, len(words) - 1):
            if words[i][-1] != words[i + 1][0]:
                return False
        
        return True