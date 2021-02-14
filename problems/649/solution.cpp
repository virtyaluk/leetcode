class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = size(senate);
        queue<int> rq, dq;
        
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }
        
        while (not empty(rq) and not empty(dq)) {
            int r = rq.front(),
                d = dq.front();
            
            rq.pop();
            dq.pop();
            
            if (r < d) {
                rq.push(r + n);
            } else {
                dq.push(d + n);
            }
        }
        
        return empty(rq) ? "Dire" : "Radiant";
    }
};