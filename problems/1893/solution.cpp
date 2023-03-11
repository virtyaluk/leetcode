class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> line(52);
        
        for (const vector<int>& range: ranges) {
            line[range[0]]++;
            line[range[1] + 1]--;
        }
        
        for (int i = 0, cur = 0; i <= right; i++) {
            cur += line[i];
            
            if (i >= left and not cur) {
                return false;
            }
        }
        
        return true;
    }
};