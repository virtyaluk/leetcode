class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int j = 0, n = size(profits);
        vector<vector<int>> pc;
        priority_queue<int> pq;
        
        for (int i = 0; i < n; i++) {
            pc.push_back({capital[i], profits[i]});
        }
        
        sort(begin(pc), end(pc));
        
        while (k--) {
            while (j < n and pc[j].front() <= w) {
                pq.push(pc[j++].back());
            }
            
            if (empty(pq)) {
                break;
            }
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};