class Solution {
public:
    double trimMean(vector<int>& arr) {
        double ans = 0.0;
        int n = arr.size();
        int skip = n * 0.05;

        sort(arr.begin(), arr.end());
        
        for (int i = skip; i < n - skip; i++) {
            ans += arr[i];
        }
        
        return ans / (double) (n - 2 * skip);
    }
};