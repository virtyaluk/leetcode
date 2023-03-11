class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        int index = 0;
        
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
        }
        
        while (size(dq) > 1) {
            index = (index + k - 1) % size(dq);
            
            dq.erase(begin(dq) + index);
        }
        
        return dq.front();
    }
};