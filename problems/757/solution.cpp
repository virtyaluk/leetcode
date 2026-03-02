class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans = 0,
            n = size(intervals);
        
        sort(begin(intervals), end(intervals), [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[1] == rhs[1]) {
                return lhs[0] > rhs[0];
            }

            return lhs[1] < rhs[1];
        });

        for (int i = 0, a = -1, b = -1; i < n; i++) {
            int lo = intervals[i][0],
                hi = intervals[i][1];
            
            if (a >= lo and b >= lo) {
                continue;
            }

            if (not (a >= lo) and not (b >= lo)) {
                ans += 2;
                b = hi;
                a = hi - 1;
            } else {
                ans++;
                a = b;
                b = hi;
            }
        }

        return ans;
    }
};