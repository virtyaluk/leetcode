class Solution {
public:
    vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {2, 4}};
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450", cur;
        int level = 0;
        queue<string> q;
        unordered_set<string> visited;
        
        for (const vector<int>& row: board) {
            for (const int& col: row) {
                cur.push_back('0' + col);
            }
        }
        
        visited.insert(cur);
        q.push(cur);
        
        while (not empty(q)) {
            for (int i = size(q) - 1; i >= 0; i--) {
                cur = q.front();
                q.pop();
                
                if (cur == target) {
                    return level;
                }
                
                auto zeroPos = cur.find('0');
                
                for (int dir: dirs[zeroPos]) {
                    string next(begin(cur), end(cur));
                    swap(next[zeroPos], next[dir]);
                    
                    if (not visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};