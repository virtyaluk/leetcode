class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long ans = 0;
        int ib1 = n,
            b2 = INT_MAX;
        vector<int> bMin1(n + 1, INT_MAX),
            bMin2(n + 1, INT_MAX);
        vector<long long> delCount(n + 1);
        
        for (const vector<int>& p: conflictingPairs) {
            int a = min(p.front(), p.back()),
                b = max(p.front(), p.back());
            
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, bMin1[i]);
            }

            ans += min(bMin1[ib1], n + 1) - i;
            delCount[ib1] += min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
        }

        return ans + *max_element(begin(delCount), end(delCount));
    }
};