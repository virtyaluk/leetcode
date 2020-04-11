class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = size(matrix),
            n = size(matrix.front());
        
        int lo = 0, hi = m * n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                el = matrix[mid / n][mid % n];
            
            if (el == target) {
                return true;
            } else if (target < el) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return false;
    }
};