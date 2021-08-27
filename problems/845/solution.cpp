class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        
        for (int i = 0; i < A.size(); i++) {
            int j = i;
            
            while (i + 1 < A.size() && A[i + 1] > A[i]) {
                i++;
            }
            
            if (j == i) {
                continue;
            }
            
            int k = i;
            
            while (k + 1 < A.size() && A[k + 1] < A[k]) {
                k++;
            }
            
            if (k == i) {
                continue;
            }
            
            ans = max(ans, k - j + 1);
            
            
        }
        
        return ans;
    }
};