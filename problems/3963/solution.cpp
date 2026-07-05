class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        ans.front() = string(n, '.');

        for (string& str: ans) {
            str.back() = '.';
        }

        return ans;
    }
};