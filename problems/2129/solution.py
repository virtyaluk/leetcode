class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return ' '.join(map(lambda word: word.lower() if len(word) <= 2 else word.lower().capitalize(), title.split(' ')))