class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int M = pizza.size(), N=pizza[0].size();
		// This data structure tells if any subarea of the matrix has apple
        vector<vector<vector<vector<bool>>>> hasApple(M, vector<vector<vector<bool>>>(N, vector<vector<bool>>(M, vector<bool>(N, false))));
        for (int width = 1; width<=N; width++) {
            for (int height=1; height<=M; height++) {
                for (int left=0; left<=N-width; left++) {
                    int right = left + width - 1;
                    for (int top=0; top<=M-height; top++) {
                        int bottom = top + height - 1;
                        if (width == 1 && height == 1) {
                            hasApple[top][left][bottom][right] = pizza[bottom][right] == 'A';
                        } else if (width == 1) {
                            hasApple[top][left][bottom][right] = hasApple[top][left][bottom-1][right] || pizza[bottom][right] == 'A';
                        } else if (height == 1) {
                            hasApple[top][left][bottom][right] = hasApple[top][left][bottom][right-1] || pizza[bottom][right] == 'A';
                        } else {
                            hasApple[top][left][bottom][right] = hasApple[top][left][bottom-1][right] || hasApple[top][left][bottom][right-1] || pizza[bottom][right] == 'A';
                        }
                        //cout << "hasApple[" << top << "][" << left << "][" << bottom << "][" << right << "]=" << hasApple[top][left][bottom][right]  << endl;
                    }
                }
            }
        }
        
        vector<vector<vector<int>>> res(M, vector<vector<int>>(N, vector<int>(k+1, 0)));
        for (int row=M-1; row>=0; row--) {
            for (int col=N-1; col>=0; col--) {                
                for (int pieces=1; pieces<=k; pieces++) {
                    long sln = 0;
                    if (pieces == 1) {
                        sln = hasApple[row][col][M-1][N-1] ? 1:0;
                    } else {
                        // vertical cut
                        for (int cutCol=col+1; cutCol < N; cutCol++) {
                            if (hasApple[row][col][M-1][cutCol-1] && res[row][cutCol][pieces-1] > 0) {
                                sln += res[row][cutCol][pieces-1];
                            }
                        }
                        // horizontal cut
                        for (int cutRow=row+1; cutRow < M; cutRow++) {
                            if (hasApple[row][col][cutRow-1][N-1] && res[cutRow][col][pieces-1] > 0) {
                                sln += res[cutRow][col][pieces-1];
                            }
                        }
                    }                    
                    res[row][col][pieces] = sln % 1000000007;
                    //cout << "res[" << row << "][" << col << "][" << pieces << "]=" << res[row][col][pieces] << endl;
                }
            }
        }
        return res[0][0][k];
    }
};