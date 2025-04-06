class Solution {
private:
    bool dfs(string& p, string& ans, vector<bool>& used, int idx) {
        if (idx == size(p) + 1) {
            return true;
        }

        for (int i = 1; i <= 9; i++) {
            if (used[i]) {
                continue;
            }

            if (idx > 0) {
                if (p[idx - 1] == 'I') {
                    int prev = ans[idx - 1] - '0';

                    if (prev > i) {
                        continue;
                    }
                } else {
                    int prev = ans[idx - 1] - '0';

                    if (prev < i) {
                        return false;
                    }
                }
            }

            ans[idx] = i + '0';
            used[i] = true;

            if (dfs(p, ans, used, idx + 1)) {
                return true;
            }

            used[i] = false;
        }

        return false;
    }
public:
    string smallestNumber(string pattern) {
        string ans(size(pattern) + 1, '1');
        vector<bool> used(10);

        dfs(pattern, ans, used, 0);

        return ans;
    }
};