class Solution {
public:
    int minimumIndex(vector<int>& c, int itemSize) {
        int n = size(c),
            minIdx = n,
            mini = 200;
        
        for (int i = 0; i < n; i++) {
            int val = c[i];

            if (val >= itemSize) {
                if (val < mini) {
                    minIdx = i;
                    mini = val;
                }
            }
        }

        if (minIdx == n) {
            return -1;
        }

        return minIdx;
    }
};