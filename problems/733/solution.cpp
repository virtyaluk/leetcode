class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int colorToReplace = image[sr][sc],
            m = size(image),
            n = size(image.back());
        
        if (colorToReplace == newColor) {
            return image;
        }
        
        q.push({sr, sc});
        
        while (not empty(q)) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x < 0 or y < 0 or x >= m or y >= n or image[x][y] != colorToReplace) {
                continue;
            }
            
            image[x][y] = newColor;
            
            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }
        
        return image;
    }
};