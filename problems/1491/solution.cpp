class Solution {
public:
    double average(vector<int>& arr) {
        double m = *min_element(begin(arr), end(arr)),
            M = *max_element(begin(arr), end(arr)),
            ans = accumulate(begin(arr), end(arr), 0.0);
        
        return (ans - m - M) / ((double) size(arr) - 2);
    }
};