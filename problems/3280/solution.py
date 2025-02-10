class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return '-'.join(num[2:] for num in map(bin, map(int, date.split('-'))))