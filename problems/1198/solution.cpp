class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        // if (mat.size() == 1) {
        //     return mat[0][0];
        // }
        
        for (const int& num: mat[0]) {
            for (int i = 0; i < mat.size(); i++) {
                if (not binary_search(begin(mat[i]), end(mat[i]), num)) {
                    break;
                }
                
                if (i == mat.size() - 1) {
                    return num;
                }
            }
        }
        
        return -1;
    }
};