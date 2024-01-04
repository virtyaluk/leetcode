class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited = {"0_0"};
        string next;
        int x = 0,
            y = 0;
        
        for (const char& ch: path) {
            if (ch == 'N') {
                y++;
            } else if (ch == 'S') {
                y--;
            } else if (ch == 'E') {
                x++;
            } else if (ch == 'W') {
                x--;
            }
            
            next = to_string(x) + "_" + to_string(y);
            
            if (visited.count(next)) {
                return true;
            }
            
            visited.insert(next);
        }
        
        return false;
    }
};