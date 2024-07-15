class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0,
        prev = 0.0;
    
        for (int i = 0; i < size(brackets); prev = brackets[i++][0]) {
            ans += max(0.0, (-prev + min(income, brackets[i][0])) * brackets[i][1] / 100.0);
        }
    
        return ans;
    }
};