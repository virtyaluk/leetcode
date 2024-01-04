class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(begin(score), end(score), [k](const auto& lhs, const auto& rhs) {
            return lhs[k] > rhs[k];
        });
        
        return score;
    }
};