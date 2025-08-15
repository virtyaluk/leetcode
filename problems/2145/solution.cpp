class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int m = 0,
            M = 0;
        
        for (int i = 0, cur = 0; i < size(d); i++) {
            cur += d[i];
            m = min(m, cur);
            M = max(M, cur);

            if (M - m > upper - lower) {
                return 0;
            }
        }

        return (upper - lower + 1) - (M - m);
    }
};