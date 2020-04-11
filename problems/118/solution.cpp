class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int row = 1; row <= numRows; row++) {
            vector<int> r(row, 1);
            
            for (int col = 1; col < row - 1; col++) {
                r[col] = ans.back()[col - 1] + ans.back()[col];
            }

            ans.push_back(r);
        }
        
        return ans;
    }
};