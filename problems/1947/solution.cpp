class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        vector<int> pos(size(students));

        iota(begin(pos), end(pos), 0);

        do {
            int cur = 0;

            for (int i = 0; i < size(students); i++) {
                for (int j = 0; j < size(students[pos[i]]); j++) {
                    cur += students[pos[i]][j] == mentors[i][j];
                }
            }

            ans = max(ans, cur);
        } while (next_permutation(begin(pos), end(pos)));

        return ans;
    }
};