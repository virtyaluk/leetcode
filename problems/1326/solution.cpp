class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans = 0, idx = 0, maxRange = 0, curRange = 0;
        vector<vector<int>> intervals;
        
        for (int i = 0; i < size(ranges); i++) {
            int left = max(i - ranges[i], 0),
                right = min(i + ranges[i], n);
            
            intervals.push_back({left, right});
        }
        
        sort(begin(intervals), end(intervals));
        
        while (maxRange < n) {
            while (idx < size(intervals) and intervals[idx][0] <= maxRange) {
                curRange = max(curRange, intervals[idx][1]);
                idx++;
            }
            
            if (curRange <= maxRange) {
                return -1;
            }
            
            maxRange = curRange;
            ans++;
        }
        
        return ans;
    }
};