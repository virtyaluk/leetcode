func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    if obstacleGrid[0][0] == 1 {
        return 0
    }
    
    rows, cols := len(obstacleGrid), len(obstacleGrid[0])
    obstacleGrid[0][0] = 1
    
    for i := 1; i < rows; i++ {
        if obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1 {
            obstacleGrid[i][0] = 1
        } else {
            obstacleGrid[i][0] = 0
        }
    }
    
    for j := 1; j < cols; j++ {
        if obstacleGrid[0][j] == 0 && obstacleGrid[0][j - 1] == 1 {
            obstacleGrid[0][j] = 1
        } else {
            obstacleGrid[0][j] = 0
        }
    }
    
    for i := 1; i < rows; i++ {
        for j := 1; j < cols; j++ {
            if obstacleGrid[i][j] == 0 {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
            } else {
                obstacleGrid[i][j] = 0
            }
        }
    }
    
    return obstacleGrid[rows - 1][cols - 1]
}