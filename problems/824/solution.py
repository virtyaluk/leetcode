class Solution:
    def toGoatLatin(self, S: str) -> str:
        if not S:
            return S
        
        vowels, words = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']), S.split()
        end = 'maa'
        
        for i, word in enumerate(words):
            if word[0] not in vowels:
                words[i] = word[1:] + word[0]
            
            words[i] += end
            end += 'a'
        
        return ' '.join(words)