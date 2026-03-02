class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int ans = 10;
        vector<int> freq(11, -1);
        freq.back() = INT_MAX;

        while (n) {
            freq[n % 10]++;
            n /= 10;
        }

        for (int i = 9; i >= 0; i--) {
            if (freq[i] != -1 && freq[i] <= freq[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};