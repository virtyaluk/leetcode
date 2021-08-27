class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        queue<int> q;
        
        q.push(0);
        
        while (not q.empty()) {
            int node = q.front();
            q.pop();
            
            if (visited[node]) {
                continue;
            }
            
            visited[node] = true;
            
            for (const int& next: rooms[node]) {
                q.push(next);
            }
        }
        
        return all_of(begin(visited), end(visited), [](const bool room) {
            return room;
        });
    }
};