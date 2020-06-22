class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        vector<int> ps;
        unordered_set<int> seen;
        queue<int> q;
        
        for (int i = 1; i * i <= n; i++) {
            ps.push_back(i * i);
        }
        
        q.push(n);
        
        while (not q.empty()) {
            for (int qlen = q.size() - 1; qlen >= 0; qlen--) {
                int nn = q.front();
                q.pop();
                
                if (seen.count(nn)) {
                    continue;
                }
                
                if (nn == 0) {
                    return ans;
                }
                
                seen.insert(nn);
                
                for (const int& square: ps) {
                    if (square > nn) {
                        break;
                    }
                    
                    q.push(nn - square);
                }
            }
            
            ans++;
        }
        
        return ans;
    }
};