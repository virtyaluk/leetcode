template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

class Solution {
private:
    int m, n;
    
    bool valid(vector<vector<char>>& grid, pair<int, int> coords) {
        auto [x, y] = coords;
        
        return x >= 0 and x < m and y >= 0 and y < n and grid[x][y] != '#';
    }
    
    bool check(vector<vector<char>>& grid, pair<int, int> cur, pair<int, int> dest, pair<int, int> box) {
        queue<pair<int, int>> q({
            cur
        });
        set<pair<int, int>> visited;
        
        while (not empty(q)) {
            auto pos = q.front();
            q.pop();
            
            if (pos == dest) {
                return true;
            }
            
            vector<pair<int, int>> nextPoss = {
                pos + make_pair(1, 0),
                pos + make_pair(-1, 0),
                pos + make_pair(0, 1),
                pos + make_pair(0, -1)
            };
            
            for (pair<int, int> nextPos: nextPoss) {
                if (valid(grid, nextPos) and nextPos != box and not visited.count(nextPos)) {
                    visited.insert(nextPos);
                    q.push(nextPos);
                }
            }
        }
        
        return false;
    }

public:
    int minPushBox(vector<vector<char>>& grid) {
        m = size(grid), n = size(grid.back());
        pair<int, int> start, box, target;
        set<pair<pair<int, int>, pair<int, int>>> visited;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    start = {i, j};
                } else if (grid[i][j] == 'B') {
                    box = {i, j};
                } else if (grid[i][j] == 'T') {
                    target = {i, j};
                }
            }
        }
        
        queue<tuple<int, pair<int, int>, pair<int, int>>> q({
            {0, box, start}
        });
        visited.insert({box, start});
        
        while (not empty(q)) {
            auto [dist, box, person] = q.front();
            q.pop();
            
            if (box == target) {
                return dist;
            }
            
            vector<pair<int, int>> boxCoords = {
                box + make_pair(1, 0),
                box + make_pair(-1, 0),
                box + make_pair(0, 1),
                box + make_pair(0, -1),
            },
            personCoords = {
                box + make_pair(-1, 0),
                box + make_pair(1, 0),
                box + make_pair(0, -1),
                box + make_pair(0, 1)
            };
            
            for (int i = 0; i < 4; i++) {
                if (valid(grid, boxCoords[i]) and not visited.count(make_pair(boxCoords[i], box))) {
                    if (valid(grid, personCoords[i]) and check(grid, person, personCoords[i], box)) {
                        visited.insert(make_pair(boxCoords[i], box));
                        q.push({dist + 1, boxCoords[i], box});
                    }
                }
            }
        }
        
        return -1;
    }
};