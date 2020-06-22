package main
type TicTacToe struct {
    n, diagonal, antiDiagonal int
    rows, cols []int
}


/** Initialize your data structure here. */
func Constructor(n int) TicTacToe {
    return TicTacToe{
        n,
        0,
        0,
        make([]int, n),
        make([]int, n),
    }
}


/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
func (this *TicTacToe) Move(row int, col int, player int) int {
    if player != 1 {
        player = -1
    }
    
    this.rows[row] += player
    this.cols[col] += player
    
    if row == col {
        this.diagonal += player
    }
    
    if col == this.n - row - 1 {
        this.antiDiagonal += player
    }
    
    if abs(this.rows[row]) == this.n || abs(this.cols[col]) == this.n || abs(this.diagonal) == this.n || abs(this.antiDiagonal) == this.n {
            if player == 1 {
                return 1
            } else {
                return 2
            }
    }
    
    return 0
}

func abs(a int) int {
    if a < 0 {
        return a * -1
    }
    
    return a
}


/**
 * Your TicTacToe object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Move(row,col,player);
 */