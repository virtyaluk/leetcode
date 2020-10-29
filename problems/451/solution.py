class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([ch * t for ch, t in Counter(s).most_common()])