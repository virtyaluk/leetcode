class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = size(arr) - k;
        vector<int> ans;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        for (int i = lo; i < lo + k; i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};