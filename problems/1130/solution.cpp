class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        
        while (arr.size() > 1) {
            int minIdx = 0;
            
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] < arr[minIdx]) {
                    minIdx = i;
                }
            }
            
            int left = minIdx > 0 ? arr[minIdx - 1] : INT_MAX;
            int right = minIdx + 1 < arr.size() ? arr[minIdx + 1] : INT_MAX;
            
            ans += min(left, right) * arr[minIdx];
            
            arr.erase(arr.begin() + minIdx);
        }
        
        return ans;
    }
};