class disjoint_set {
public:
    unordered_map<int, int> parent;
    
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void merge(int x, int y) {
        if (not parent.count(x)) {
            parent[x] = x;
        }
        
        if (not parent.count(y)) {
            parent[y] = y;
        }
        
        int px = find(x), py = find(y);
        
        if (px != py) {
            parent[px] = py;
        }
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix.back());
        vector<int> rank(m + n);
        map<int, vector<pair<int, int>>> groupByVal;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                groupByVal[matrix[i][j]].push_back({i, j});
            }
        }
        
        for (const auto &[_, cells]: groupByVal) {
            disjoint_set ds;
            unordered_map<int, vector<int>> groups;
            
            for (const auto &[i, j]: cells) {
                ds.merge(i, j + m);
            }
            
            for (const auto& [x, _]: ds.parent) {
                groups[ds.find(x)].push_back(x);
            }
            
            for (const auto& [_, group]: groups) {
                int maxRank = 0;
                
                for (const int& i: group) {
                    maxRank = max(maxRank, rank[i]);
                }
                
                for (const int& i: group) {
                    rank[i] = maxRank + 1;
                }
            }
            
            for (const auto &[i, j]: cells) {
                matrix[i][j] = rank[i];
            }
        }
        
        return matrix;
    }
};