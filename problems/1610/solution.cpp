class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0, common = 0;
        vector<double> pts;
        
        for (const vector<int>& point: points) {
            double xdif = point[0] - location[0],
                ydif = point[1] - location[1];
            
            if (xdif == 0 and ydif == 0) {
                common++;
                continue;
            }
            
            double pointEq = atan2(xdif, ydif) * 180 / M_PI;
            
            if (pointEq < 0) {
                pointEq += 360;
            }
            
            pts.push_back(pointEq);
        }
        
        sort(begin(pts), end(pts));
        
        for (int i = 0, n = size(pts); i < n; i++) {
            pts.push_back(pts[i] + 360);
        }
        
        for (int left = 0, right = 0; right < size(pts); right++) {
            if (left < right && pts[right] - pts[left] > angle) {
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        // copy(begin(pts), end(pts), ostream_iterator<double>(cout, ", "));
        // cout << endl;
        
        return ans + common;
    }
};