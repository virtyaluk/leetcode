class Solution {
private:
    vector<int> fa, rank;

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }

        return fa[x];
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        fa[y] = x;

        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = size(source),
            ans = 0;
        unordered_map<int, unordered_map<int, int>> um;

        fa.resize(n);
        rank.resize(n, 0);

        iota(begin(fa), end(fa), 0);

        for (auto& p: allowedSwaps) {
            uni(p.front(), p.back());
        }

        for (int i = 0; i < n; i++) {
            int f = find(i);
            um[f][source[i]]++;
        }

        for (int i = 0; i < n; i++) {
            int f = find(i);

            if (um[f][target[i]] > 0) {
                um[f][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};