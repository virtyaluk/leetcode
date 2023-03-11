class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = 0;
        priority_queue<int> pq(begin(piles), end(piles));
        
        while (k) {
pq.push((pq.top() + 1) / 2);
            pq.pop();
            k--;
}
        
        while (not empty(pq)) {
ans += pq.top();
            pq.pop();
}
        
        return ans;
    }
};