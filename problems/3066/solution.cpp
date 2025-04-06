class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long long int, vector<long long int>, greater<>> q(begin(nums), end(nums));

        while (not empty(q) and q.top() < k) {
            long long int x = q.top();
            q.pop();
            long long int y = q.top();
            q.pop();

            q.push(min(x, y) * 2 + max(x, y));
            ans++;
        }

        return ans;
    }
};