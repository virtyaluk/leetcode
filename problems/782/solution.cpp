class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = size(board),
            rowSum = 0,
            colSum = 0,
            rowSwap = 0,
            colSwap = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) {
                    return -1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowSwap += board[i][0] == i % 2;
            colSwap += board[0][i] == i % 2;
        }
        
        if (rowSum != n / 2 and rowSum != (n + 1) / 2) {
            return -1;
        }
        
        if (colSum != n / 2 and colSum != (n + 1) / 2) {
            return -1;
        }
        
        if (n % 2) {
            if (colSwap % 2) {
                colSwap = n - colSwap;
            }
            
            if (rowSwap % 2) {
                rowSwap = n - rowSwap;
            }
        } else {
            colSwap = min(n - colSwap, colSwap);
            rowSwap = min(n - rowSwap, rowSwap);
        }
        
        return (rowSwap + colSwap) / 2;
    }
};