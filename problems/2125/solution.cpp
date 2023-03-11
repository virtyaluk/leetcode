class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        
        for (const string& row: bank) {
            int cur = count(begin(row), end(row), '1');
            
            if (cur) {
                ans += prev * cur;
                prev = cur;
            }
        }
        
        return ans;
    }
};