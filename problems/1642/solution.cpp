class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int i = 0;
        priority_queue<int> pq;
        
        for (; i < h.size() - 1; i++) {
            int jump = h[i + 1] - h[i];
                
            if (jump > 0) {
                pq.push(jump);
                b -= jump;
                
                if (b >= 0) {
                    continue;
                }
                
                if (not l) {
                    break;
                }
                
                b += pq.top();
                pq.pop();
                l--;
            }
        }
        
        return i;
    }
};