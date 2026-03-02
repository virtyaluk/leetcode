class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for (const int& h: happiness) {
            pq.push(h);
        }

        for (int i = 0, turns = 0; i < k; i++) {
            ans += max(pq.top() - turns, 0);
            pq.pop();
            turns++;
        }
        
        return ans;
    }
};