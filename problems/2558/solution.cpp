class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long int ans = 0;
        priority_queue<int> pq(begin(gifts), end(gifts));
        
        while (k--) {
            int x = sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }
        
        while (not empty(pq)) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};