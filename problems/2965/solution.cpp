class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2, 0);
        unordered_set<int> us;
        
        for (const vector<int>& row: grid) {
            for (const int& num: row) {
                if (us.count(num)) {
                    ans[0] = num;
                }
                
                us.insert(num);
            }
        }
        
        for (int i = 1; i <= pow(size(grid), 2); i++) {
            if (not us.count(i)) {
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};