class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [&](vector<int>& a, vector<int>& b) {
            return a.back() - a.front() > b.back() - b.front();
        });

        int ans = 0,
            remain = 0;

        for (auto task : tasks) {
            ans += remain > task.back() ? 0 : task.back() - remain;
            remain = max(task.back() - task.front(), remain - task.front());
        }

        return ans;
    }
};