class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int lo = toBeRemoved[0], hi = toBeRemoved[1];
        
        for (vector<int> i: intervals) {
            int a = i[0], b = i[1];
            
            if (b <= lo || a >= hi) {
                ans.push_back(i);
            } else if (a < lo && b > hi) {
                ans.push_back({a, lo});
                ans.push_back({hi, b});
            } else if (a < lo && b <= hi) {
                ans.push_back({a, lo});
            } else if (a >= lo && b > hi) {
                ans.push_back({hi, b});
            }
        }
        
        return ans;
    }
};