class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = size(coordinates);
        
        if (n == 2) {
            return true;
        }
        
        long long int run = coordinates[1][0] - coordinates[0][0],
            rise = coordinates[1][1] - coordinates[0][1];
        
        for (int i = 2; i < n; i++) {
            long long int run1 = coordinates[i][0] - coordinates[0][0],
                rise1 = coordinates[i][1] - coordinates[0][1];
            
            if (run * rise1 != rise * run1) {
                return false;
            }
        }
        
        return true;
    }
};