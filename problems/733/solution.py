class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc] == newColor:
            return image
        
        self.do(image, sr, sc, newColor, image[sr][sc])
        
        return image
    
    def do(self, img, x, y, newColor, oldColor):
        if x < 0 or x >= len(img) or y < 0 or y >= len(img[0]) or img[x][y] != oldColor:
            return
        
        img[x][y] = newColor
        
        self.do(img, x - 1, y, newColor, oldColor)
        self.do(img, x + 1, y, newColor, oldColor)
        self.do(img, x, y - 1, newColor, oldColor)
        self.do(img, x, y + 1, newColor, oldColor)