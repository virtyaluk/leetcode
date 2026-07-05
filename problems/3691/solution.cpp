class SegTree {
    vector<int> maxv, minv;
    int n;

public:
    SegTree(vector<int>& nums) {
        n = size(nums);
        maxv.resize(n * 4);
        minv.resize(n * 4);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }

        int m = (l + r) / 2;

        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);

        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l and r <= qr) {
            return maxv[node];
        }

        int m = (l + r) / 2,
            ans = INT_MIN;
        
        if (ql <= m) {
            ans = max(ans, queryMax(node * 2, l, m, ql, qr));
        }

        if (qr > m) {
            ans = max(ans, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }

        return ans;
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l and r <= qr) {
            return minv[node];
        }

        int m = (l + r) / 2,
            ans = INT_MAX;
        
        if (ql <= m) {
            ans = min(ans, queryMin(node * 2, l, m, ql, qr));
        }

        if (qr > m) {
            ans = min(ans, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }

        return ans;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = size(nums);
        SegTree seg(nums);
        priority_queue<tuple<int, int, int>> pq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            pq.emplace(seg.queryMax(1, 0, n - 1, i, n - 1) - seg.queryMin(1, 0, n - 1, i, n - 1), i, n - 1);
        }

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;

            if (r > l) {
                pq.emplace(seg.queryMax(1, 0, n - 1, l, r - 1) - seg.queryMin(1, 0, n - 1, l, r - 1), l, r - 1);
            }
        }

        return ans;
    }
};