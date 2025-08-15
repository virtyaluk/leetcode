class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> pq;
        vector<int> vi(size(nums) + 1);
        int ops = 0;

        sort(begin(queries), end(queries), [](const vector<int>& a, const vector<int>& b) {
            return a.front() < b.front();
        });

        for (int i = 0, j = 0; i < size(nums); i++) {
            ops += vi[i];

            while (j < size(queries) and queries[j].front() == i) {
                pq.push(queries[j].back());
                j++;
            }

            while (ops < nums[i] and not empty(pq) and pq.top() >= i) {
                ops++;
                vi[pq.top() + 1]--;
                pq.pop();
            }

            if (ops < nums[i]) {
                return -1;
            }
        }

        return size(pq);
    }
};