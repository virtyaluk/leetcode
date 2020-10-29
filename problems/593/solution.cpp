class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        
        sort(p.begin(), p.end(), [](vector<int>& l, vector<int>& r) {
            return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
        });
        
        return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) && dist(p[1], p[3]) == dist(p[3], p[2]) && dist(p[3], p[2]) == dist(p[2], p[0]) && dist(p[0],p[3]) == dist(p[1], p[2]);
    }
    
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }
};