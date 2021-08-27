class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int x = 0, y = 0, dir = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        map<int, set<int>> obsts;
        
        for (vector<int> obst: obstacles) {
            obsts[obst[0]].insert(obst[1]);
        }
        
        for (int com: commands) {
            switch (com) {
                case -2:
                    dir = (dir + 3) % 4;
                    break;
                case -1:
                    dir = (dir + 1) % 4;
                    break;
                default:
                    for (int step = 0; step < com; step++) {
                        int newX = x + dx[dir], newY = y + dy[dir];
                        bool hasNoObstNextToIt = obsts.find(newX) == obsts.end() || obsts[newX].find(newY) == obsts[newX].end();
                        
                        if (hasNoObstNextToIt) {
                            x = newX;
                            y = newY;
                            ans = max(ans, x * x + y * y);
                        }
                    }
                    
                    break;
            }
        }
        
        return ans;
    }
};