class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        if (empty(a) or empty(b)) {
            return {};
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0, j = 0; i < size(a) and j < size(b);) {
            int start = max(a[i][0], b[j][0]),
                end = min(a[i][1], b[j][1]);
            
            if (start <= end) {
                ans.push_back({start, end});
            }
            
            if (a[i][1] < b[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};