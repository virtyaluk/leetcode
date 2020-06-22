class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int n = buildings.size();
        
        if (buildings.empty()) {
            return ans;
        }
        
        if (n == 1) {
            ans.push_back({buildings[0][0], buildings[0][2]});
            ans.push_back({buildings[0][1], 0});
            
            return ans;
        }
        
        vector<vector<int>> left(buildings.begin(), buildings.begin() + n/2), right(buildings.begin() + n/2, buildings.end());
        vector<vector<int>> leftBuildings = getSkyline(left), rightBuildings = getSkyline(right);
        
        return mergeSkylines(leftBuildings, rightBuildings);
    }
    
    vector<vector<int>> mergeSkylines(vector<vector<int>>& left, vector<vector<int>>& right) {
        vector<vector<int>> ans;
        
        int curLeft = 0, curRight = 0, curY = 0, leftY = 0, rightY = 0, x, maxY;
        
        while (curLeft < left.size() && curRight < right.size()) {
            vector<int> leftPoint = left[curLeft], rightPoint = right[curRight];
            
            if (leftPoint.front() < rightPoint.front()) {
                x = leftPoint.front();
                leftY = leftPoint[1];
                curLeft++;
            } else {
                x = rightPoint.front();
                rightY = rightPoint[1];
                curRight++;
            }
            
            maxY = max(leftY, rightY);
            
            if (curY != maxY) {
                updateOutput(ans, x, maxY);
                curY = maxY;
            }
        }
        
        appendSkyline(ans, left, curLeft, left.size(), curY);
        appendSkyline(ans, right, curRight, right.size(), curY);
        
        return ans;
    }
    
    void updateOutput(vector<vector<int>>& output, int x, int y) {
        if (output.empty() || output.back().front() != x) {
            output.push_back({x, y});
        } else {
            output.back()[1] = y;
        }
    }
    
    void appendSkyline(vector<vector<int>>& output, vector<vector<int>>& skyline, int p, int n, int curY) {
        while (p < n) {
            vector<int> point = skyline[p];
            int x = point.front(), y = point[1];
            p++;
            
            if (curY != y) {
                updateOutput(output, x, y);
                curY = y;
            }
        }
    }
};