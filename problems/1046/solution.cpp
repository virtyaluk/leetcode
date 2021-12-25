class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for (const int& stone: stones) {
            pq.push(stone);
        }
        
        while (size(pq) > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if (x != y) {
                pq.push(y - x);
            }
        }
        
        return empty(pq) ? 0 : pq.top();
    }
};