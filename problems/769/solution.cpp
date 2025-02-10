class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        
        for (int i = 0, M = 0; i < size(arr); i++) {
            M = max(M, arr[i]);
            ans += M == i;
        }
        
        return ans;
    }
};