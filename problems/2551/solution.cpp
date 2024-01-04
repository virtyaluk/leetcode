class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = size(weights);
        long long ans = 0;
        vector<long long> pw(n - 1);
        
        for (int i = 0; i < n - 1; i++) {
            pw[i] += weights[i] + weights[i + 1];
        }
        
        sort(begin(pw), end(pw));
        
        for (int i = 0; i < k - 1; i++) {
            ans += pw[n - 2 - i] - pw[i];
        }
        
        return ans;
    }
};