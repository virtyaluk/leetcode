class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        int ans = n + 1;
        vector<long long> prefSum(n + 1);
        deque<int> q;
        
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + (long long) A[i];
        }
        
        
        for (int i = 0; i < prefSum.size(); i++) {
            while (!q.empty() && prefSum[i] - prefSum[q.front()] >= K) {
                ans = min(ans, i - q.front());
                
                q.pop_front();
            }
            
            while (!q.empty() && prefSum[i] <= prefSum[q.back()]) {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};