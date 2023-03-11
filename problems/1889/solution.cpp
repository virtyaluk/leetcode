const int MOD = 1e9 + 7;

class Solution {
public:

    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size(),
            m = boxes.size();
        vector<long long> prefSum(n);
        long long int ans = 1e18;
        
        sort(begin(packages), end(packages));
        
        prefSum[0] = packages[0];
        
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + packages[i];
        }
        
        for (int i = 0; i < m; i++) {
            sort(begin(boxes[i]), end(boxes[i]));
            
            long long int packagedSpace = 0, packagedCount = 0, wastedSpace = 0;

            for (const int& box: boxes[i]) {
                auto it = upper_bound(begin(packages), end(packages), box);
                
                if (it != begin(packages)) {
                    it--;
                    int packageIdx = it - begin(packages);
                    wastedSpace += (packageIdx + 1 - packagedCount) * box - (prefSum[packageIdx] - packagedSpace);
                    packagedCount = packageIdx + 1;
                    packagedSpace = prefSum[packageIdx];
                }
            }
            
            if (packagedCount == n) {
                ans = min(ans, wastedSpace);
            }
        }
        
        if (ans == 1e18) {
            return -1;
        }
        
        return ans % MOD;
    }
};