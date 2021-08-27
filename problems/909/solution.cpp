class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = size(board);
        vector<bool> visited(n * n + 1);
        vector<int> b{0};
        bool even = true;
        queue<pair<int, int>> q({{1, 0}});
        
        for (auto it = rbegin(board); it != rend(board); it++) {
            if (even) {
                b.insert(end(b), begin(*it), end(*it));
            } else {
                b.insert(end(b), rbegin(*it), rend(*it));
            }
            
            even = !even;
        }
        
        visited[0] = visited[1] = true;
        
        while (not empty(q)) {
            auto [pos, moves] = q.front();
            q.pop();
            
            for (int next = pos + 1; next <= min(pos + 6, n * n); next++) {
                if (visited[next]) {
                    continue;
                }
                
                if (next == n * n) {
                    return moves + 1;
                }
                
                visited[next] = true;
                
                if (b[next] != -1) {
                    if (b[next] == n * n) {
                        return moves + 1;
                    }
                    
                    q.push({b[next], moves + 1});
                } else {
                    q.push({next, moves + 1});
                }
            }
        }
        
        return -1;
    }
};