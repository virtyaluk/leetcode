const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    for (int i = 2; i < MX; i++) {
        if (empty(factors[i])) {
            for (int j = i; j < MX; j += i) {
                factors[j].push_back(i);
            }
        }
    }

    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = size(nums),
            ans = 0;
        unordered_map<int, vector<int>> edges;
        vector<bool> seen(n);
        vector<int> q = {0};

        seen.front() = true;

        for (int i = 0; i < n; i++) {
            for (int p: factors[nums[i]]) {
                edges[p].push_back(i);
            }
        }

        while (true) {
            vector<int> q2;

            for (int i: q) {
                if (i == n - 1) {
                    return ans;
                }

                if (i > 0 and not seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }

                if (i < n - 1 and not seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }

                if (size(factors[nums[i]]) == 1) {
                    int p = nums[i];

                    if (edges.count(p)) {
                        for (int j: edges[p]) {
                            if (not seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }

                        edges[p].clear();
                    }
                }
            }

            q = move(q2);
            ans++;
        }

        return ans;
    }
};