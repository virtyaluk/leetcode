class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = size(matrix), lo = matrix[0][0], hi = matrix.back().back();
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                count = 0;
            
            for (int i = 0; i < n; i++) {
                auto it = lower_bound(begin(matrix[i]), end(matrix[i]), mid);
                count += it - begin(matrix[i]);
            }
            
            if (count < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo - 1;
    }
    
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        for (const vector<int>& row: matrix) {
            for (const int& num: row) {
                pq.push(num);
                
                if (size(pq) > k) {
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};