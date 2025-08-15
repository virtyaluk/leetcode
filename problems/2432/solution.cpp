class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0,
            maxTime = 0;

        for (int i = 0, prev = 0, time = 0; i < size(logs); i++) {
            time = logs[i].back() - prev;

            if (maxTime <= time) {
                ans = maxTime < time ? logs[i].front() : min(ans, logs[i].front());
                maxTime = time;
            }

            prev = logs[i].back();
        }

        return ans;
    }
};