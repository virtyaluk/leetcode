class Solution {
private:
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> us;
        fences.push_back(1);
        fences.push_back(border);

        sort(begin(fences), end(fences));

        for (int i = 0; i < size(fences); i++) {
            for (int j = i + 1; j < size(fences); j++) {
                us.insert(fences[j] - fences[i]);
            }
        }

        return us;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int ans = 0;

        for (auto& e: hEdges) {
            if (vEdges.count(e)) {
                ans = max(ans, e);
            }
        }

        if (ans == 0) {
            ans = -1;
        } else {
            ans = 1ll * ans * ans % 1000000007;
        }

        return ans;
    }
};