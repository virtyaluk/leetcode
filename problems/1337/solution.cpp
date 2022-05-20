class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans(k);
        priority_queue<pair<int, int>> q;
        
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            
            q.push({count, i});
            
            if (q.size() > k) {
                q.pop();
            }
        }
        
        while (k) {
            ans[--k] = q.top().second;
            q.pop();
        }
        
        return ans;
    }
};