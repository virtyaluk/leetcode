class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0,
            n = size(points);
        
        for (int i = 0; i < n; i++) {
            vector<int>& pa = points[i];

            for (int j = 0; j < n; j++) {
                vector<int> pb = points[j];
                bool ok = false;

                if (i == j or not (pa[0] <= pb[0] and pa[1] >= pb[1])) {
                    continue;
                }

                if (n == 2) {
                    ans++;
                    continue;
                }

                for (int k = 0; k < n; k++) {
                    if (k == i or k == j) {
                        continue;
                    }

                    vector<int> pc = points[k];
                    bool xok = pc[0] >= pa[0] and pc[0] <= pb[0],
                        yok = pc[1] <= pa[1] and pc[1] >= pb[1];
                    
                    if (xok and yok) {
                        ok = true;
                        
                        break;
                    }
                }

                if (not ok) {
                    ans++;
                }
            }
        }

        return ans;
    }
};