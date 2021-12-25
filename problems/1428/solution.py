# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        [rows, cols] = binaryMatrix.dimensions()
        
        rows -= 1
        cols -= 1
        
        row, col = 0, cols
        
        while row <= rows and col >= 0:
            if binaryMatrix.get(row, col):
                col -= 1
            else:
                row += 1
        
        return -1 if col == cols else col + 1