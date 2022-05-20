class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        
        for (int i = 0; i < size(arr1); i++) {
            bool flag = true;
            
            for (int j = 0; j < size(arr2); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    flag = false;
                    break;
                }
            }
            
            ans += flag;
        }
        
        return ans;
    }
};