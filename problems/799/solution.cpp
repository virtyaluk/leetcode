class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> m(100, vector<double>(100, 0.0));
        m[0][0] = poured;
        
        for (int r = 0; r < query_row; r++) {
            for (int c = 0; c <= r; c++) {
                double q = (m[r][c] - 1) / 2.0;
                
                if (q > 0) {
                    m[r + 1][c] += q;
                    m[r + 1][c + 1] += q;
                }
            }
        }
        
        return min(1.0, m[query_row][query_glass]);
    }
    
     double champagneTower1(int poured, int query_row, int query_glass) {
         vector<double> row(1);
         row[0] = poured;
         
         for (int r = 0; r < query_row; r++) {
             vector<double> newRow(r + 2);
             
             for (int c = 0; c <= r; c++) {
                 double q = (row[c] - 1.0) / 2.0;
                 
                 if (q > 0) {
                     newRow[c] += q;
                     newRow[c + 1] += q;
                 }
             }
             
             row = newRow;
         }
         
         return min(1.0, row[query_glass]);
     }
};