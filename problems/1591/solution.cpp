typedef short i16;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int, short[4]> coords;
        unordered_set<int> colors;
        i16 m = size(targetGrid), n = size(targetGrid.front());
        
        for (i16 i = 0; i < m; i++) {
            for (i16 j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                
                if (not coords.count(color)) {
                    coords[color][0] = m;
                    coords[color][1] = n;
                    coords[color][2] = -m;
                    coords[color][3] = -n;
                }
                
                coords[color][0] = min(coords[color][0], i);
                coords[color][1] = min(coords[color][1], j);
                coords[color][2] = max(coords[color][2], i);
                coords[color][3] = max(coords[color][3], j);
                
                colors.insert(color);
            }
        }
        
        while (not empty(colors)) {
            unordered_set<int> nextColors;
            
            for (const int& color: colors) {
                if (not erase(targetGrid, coords[color], color)) {
                    nextColors.insert(color);
                }
            }
            
            if (size(colors) == size(nextColors)) {
                return false;
            }
            
            colors = nextColors;
        }
        
        return true;
    }
    
    bool erase(vector<vector<int>>& grid, i16 (&coord)[4], int color) {
        for (i16 i = coord[0]; i <= coord[2]; i++) {
            for (i16 j = coord[1]; j <= coord[3]; j++) {
                if (grid[i][j] > 0 and grid[i][j] != color) {
                    return false;
                }
            }
        }
        
        for (i16 i = coord[0]; i <= coord[2]; i++) {
            for (i16 j = coord[1]; j <= coord[3]; j++) {
                grid[i][j] = 0;
            }
        }
        
        return true;
    }
};