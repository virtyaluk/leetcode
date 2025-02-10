class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans = 0;
        unordered_map<string, int> um;
        
        for (const vector<int>& row: matrix) {
            bitset<301> bs;
            
            bs.flip();
            
            for (int i = 1; i < size(row); i++) {
                bs[i] = row[i] != row.front() ? false : true;
            }
            
            ans = max(ans, ++um[bs.to_string()]);
        }
        
        return ans;
    }
};