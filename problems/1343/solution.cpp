class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0,
            avg = accumulate(begin(arr), begin(arr) + k, 0);
        
        ans += (avg / k) >= threshold;
        
        for (int i = k; i < size(arr); i++) {
            avg -= arr[i - k];
            avg += arr[i];
            ans += (avg / k) >= threshold;
        }
        
        return ans;
    }
};