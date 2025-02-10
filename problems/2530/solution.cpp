class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(begin(nums), end(nums));
        
        while (k--) {
            ans += pq.top();
            
            double next = pq.top();
            
            pq.pop();
            pq.push(ceil(next / 3.0));
        }
        
        return ans;
    }
};