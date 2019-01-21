class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = size(matrix), n = size(matrix.back());
        int top = 0, left = 0, right = n - 1, down = m - 1;
        
        while (size(ans) < m * n) {
            // left -> right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            
            // top -> down
            for (int i = top + 1; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            
            
            // // right -> left
            if (top != down) {
                for (int i = right - 1; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
            }
            
            // down -> top
            if (left != right) {
                for (int i = down - 1; i > top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            
            left++;
            right--;
            top++;
            down--;
        }
        
        return ans;
    }
};