class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size()));
        
        return dfs(maze, start, destination, visited);
    }
    
    bool dfs(vector<vector<int>>& grid, vector<int>& start, vector<int>& dest, vector<vector<bool>>& visited) {
        if (visited[start[0]][start[1]]) {
            return false;
        }
        
        if (start[0] == dest[0] && start[1] == dest[1]) {
            return true;
        }
        
        visited[start[0]][start[1]] = true;
        
        int up = start[0] - 1, right = start[1] + 1, down = start[0] + 1, left = start[1] - 1;
        
        // up
        while (up >= 0 && grid[up][start[1]] == 0) { up--; }
        vector<int> upStart({up + 1, start[1]});
        if (dfs(grid, upStart, dest, visited)) { return true; }
        
        // right
        while (right < grid[0].size() && grid[start[0]][right] == 0) { right++; }
        vector<int> rightStart({start[0], right - 1});
        if (dfs(grid, rightStart, dest, visited)) { return true; }
        
        // down
        while (down < grid.size() && grid[down][start[1]] == 0) { down++; }
        vector<int> downStart({down - 1, start[1]});
        if (dfs(grid, downStart, dest, visited)) { return true; }
        
        // left
        while (left >= 0 && grid[start[0]][left] == 0) { left--; }
        vector<int> leftStart({start[0], left + 1});
        if (dfs(grid, leftStart, dest, visited)) { return true; }
        
        return false;
    }
};