class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& is) {
        int ans = 0, lastEnd = 0;
        
        sort(is.begin(), is.end(), [&](vector<int> l, vector<int> r) -> bool {
            return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0]; 
        });
        
        for (vector<int> i: is) {
            if (i[1] > lastEnd) {
                ans++;
                lastEnd = i[1];
            }
        }
        
        return ans;
    }
};