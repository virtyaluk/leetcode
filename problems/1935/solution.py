class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        return len([word for word in text.split() if not set(word).intersection(set(brokenLetters))])