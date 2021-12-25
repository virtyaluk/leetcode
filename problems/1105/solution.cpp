class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        
        return dfs(dp, books, shelfWidth, 0, 0, shelfWidth);
    }
    
    int dfs(
        vector<vector<int>>& dp,
        vector<vector<int>>& books,
        int width,
        int idx,
        int height,
        int shelfWidth
    ) {
        if (idx >= size(books)) {
            return height;
        }
        
        if (dp[idx][width] != -1) {
            return dp[idx][width];
        }
        
        int bookWidth = books[idx][0],
            bookHeight = books[idx][1],
            ans = height + dfs(
                dp,
                books,
                shelfWidth - bookWidth,
                idx + 1,
                bookHeight,
                shelfWidth
            );
        
        if (bookWidth <= width) {
            ans = min(ans, dfs(
                dp,
                books,
                width - bookWidth,
                idx + 1,
                max(height, bookHeight),
                shelfWidth
            ));
        }
        
        return dp[idx][width] = ans;
    }
};