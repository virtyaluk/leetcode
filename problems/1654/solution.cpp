class Solution {
private:
    int getKey(int a, int b) {
        return 1e6 * a + b;
    }
    
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int ans = 0, n = x + a + b;
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        
        for (const int& pos: forbidden) {
            visited.insert(getKey(0, pos));
            visited.insert(getKey(1, pos));
            n = max(n, pos + a + b);
        }
        
        q.push({0, 0});
        
        while (not empty(q)) {
            for (int i = size(q); i > 0; i--) {
                auto [dir, pos] = q.front();
                q.pop();
                
                if (pos == x) {
                    return ans;
                }
                
                pair<int, int> forward = {0, pos + a},
                    backward = {1, pos - b};
                
                if (pos + a <= n and visited.insert(getKey(0, pos + a)).second) {
                    q.push(forward);
                }
                
                if (dir == 0 and pos - b >= 0 and visited.insert(getKey(1, pos - b)).second) {
                    q.push(backward);
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};