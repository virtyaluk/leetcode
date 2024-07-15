class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& tt) {
        int a = 0, b = 0, c = 0;
        
        for (const vector<int>& t: triplets) {
            if (t[0] <= tt[0] and t[1] <= tt[1] and t[2] <= tt[2]) {
                a = max(a, t[0]);
                b = max(b, t[1]);
                c = max(c, t[2]);
            }
        }
        
        return a == tt[0] and b == tt[1] and c == tt[2];
    }
};