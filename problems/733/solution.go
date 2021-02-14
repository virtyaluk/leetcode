package main
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
    if image[sr][sc] == newColor {
        return image
    }
    
    dfs(image, sr, sc, newColor, image[sr][sc])
    
    return image
}

func dfs(img [][]int, x, y, newColor, colorToReplace int) {
    if x < 0 || x >= len(img) || y < 0 || y >= len(img[0]) || img[x][y] != colorToReplace {
        return
    }
    
    img[x][y] = newColor
    
    dfs(img, x + 1, y, newColor, colorToReplace)
    dfs(img, x - 1, y, newColor, colorToReplace)
    dfs(img, x, y + 1, newColor, colorToReplace)
    dfs(img, x, y - 1, newColor, colorToReplace)
}