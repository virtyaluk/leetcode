class Solution {
    unordered_map<int, int> parent;
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        
        parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    bool merge(int x, int y) {
        int parentX = find(x),
            parentY = find(y);
        
        if (parentX == parentY) {
            return false;
        }
        
        parent[parentX] = parentY;
        
        return true;
    }
    
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        int count = 0;
        
        for (const vector<int>& pos: positions) {
            int x = pos[0], y = pos[1], id = x * n + y;
            
            if (parent.count(id)) {
                ans.push_back(count);
                continue;
            }
            
            count++;
            parent[id] = id;
            
            for (auto dir: dirs) {
                int nx = x + dir[0], ny = y + dir[1], nid = nx * n + ny;
                
                if (nx < 0 or nx >= m or ny < 0 or ny >= n) {
                    continue;
                }
                
                if (not parent.count(nid)) {
                    continue;
                }
                
                if (merge(id, nid)) {
                    count--;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};