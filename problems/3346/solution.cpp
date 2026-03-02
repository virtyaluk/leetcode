class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m = 1e9,
            M = -1e9,
            ans = 0;
        
        for (const int& num: nums) {
            M = max(M, num);
            m = min(m, num);
        }

        vector<int> freq(M + 1);

        for (const int& num: nums) {
            freq[num]++;
        }

        for (int i = 1; i <= M; i++) {
            freq[i] += freq[i - 1];
        }

        for (int i = m; i <= M; i++) {
            int l = max(m, i - k),
                r = min(M, i + k),
                f = freq[i] - freq[i - 1],
                ef = min(numOperations, freq[r] - freq[l - 1] - f);
            ans = max(ans, f + ef);
        }

        return ans;
    }
};