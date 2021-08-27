package main
func numRookCaptures(board [][]byte) int {
    captured, x, y := 0, 0, 0
    
    for i, row := range board {
        for j, coll := range row {
            if coll == 'R' {
                x, y = i, j
                break
            }
        }
    }
    
    for up := x - 1; up >= 0; up-- {
        if board[up][y] == 'p' {
            captured++
            break
        } else if board[up][y] == 'B' {
            break
        }
    }
    
    for down := x + 1; down < 8; down++ {
        if board[down][y] == 'p' {
            captured++
            break
        } else if board[down][y] == 'B' {
            break
        }
    }
    
    for left := y - 1; left >= 0; left-- {
        if board[x][left] == 'p' {
            captured++
            break
        } else if board[x][left] == 'B' {
            break
        }
    }
    
    for right := y + 1; right < 8; right++ {
        if board[x][right] == 'p' {
            captured++
            break
        } else if board[x][right] == 'B' {
            break
        }
    }
    
    return captured
}