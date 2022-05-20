const int MOD = 1e9 + 7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        long long int ans = 0, maxSpeed = 0;
        vector<pair<long long int, long long int>> engineers;
        priority_queue<long long int, vector<long long int>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            engineers.push_back({s[i], e[i]});
        }
        
        sort(begin(engineers), end(engineers), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });
        
        for (auto &[speed, eff]: engineers) {
            maxSpeed += speed;
            
            if (pq.size() > k - 1) {
                maxSpeed -= pq.top();
                pq.pop();
            }
            
            pq.push(speed);
            
            ans = max(ans, maxSpeed * eff);
        }
        
        return ans % MOD;
    }
};