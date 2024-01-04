class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long int ans = 0;
        int cnt = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        
        while (not empty(pq) and cnt != n) {
            ans = pq.top();
            
            for (const int prime: primes) {
                pq.push(prime * ans);
            }
            
            while (not empty(pq) and pq.top() == ans) {
                pq.pop();
            }
            
            cnt++;
        }
        
        return ans;
    }
};