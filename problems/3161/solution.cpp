class Solution {
private:
    vector<int> bt;

    void update(int x, int v) {
        for (; x < size(bt); x += x & -x) {
            bt[x] = max(bt[x], v);
        }
    }

    int query(int x) {
        int ans = 0;

        for (; x > 0; x -= x & -x) {
            ans = max(ans, bt[x]);
        }

        return ans;
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000,
            pre = 0;
        set<int> s = {0, mx};
        vector<bool> ans;

        for (auto& q: queries) {
            if (q.front() == 1) {
                s.insert(q[1]);
            }
        }

        bt.resize(mx + 1);

        for (int x: s) {
            if (not x) {
                continue;
            }

            update(x, x - pre);
            
            pre = x;
        }

        reverse(begin(queries), end(queries));

        for (auto& q: queries) {
            if (q.front() == 2) {
                int x = q[1],
                    sz = q[2];
                auto it = s.upper_bound(x);
                --it;
                int pre = *it,
                    maxSpace = query(pre);
                maxSpace = max(maxSpace, x - pre);

                ans.push_back(maxSpace >= sz);
            } else {
                int x = q[1];
                auto it = s.find(x);
                int pre = *prev(it),
                    nxt = *next(it);
                
                update(nxt, nxt - pre);
                s.erase(it);
            }
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};