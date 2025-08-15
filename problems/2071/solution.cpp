class Solution {
private:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, const int& strength, const int& mid) {
        int m = size(workers),
            pIdx = m - 1;
        deque<int> dq;

        for (int i = mid - 1; i >= 0; i--) {
            while (pIdx >= m - mid and workers[pIdx] + strength >= tasks[i]) {
                dq.push_front(workers[pIdx]);
                pIdx--;
            }

            if (empty(dq)) {
                return false;
            } else if (dq.back() >= tasks[i]) {
                dq.pop_back();
            } else {
                if (not pills) {
                    return false;
                }

                pills--;

                dq.pop_front();
            }
        }

        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int ans = 0,
            lo = 1,
            hi = min(size(tasks), size(workers));

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(tasks, workers, pills, strength, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};