class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        unordered_map<int, int> freq;

        while (n != 0) {
            int d = n % 10;
            n /= 10;
            freq[d]++;
        }

        for (auto& [d, f]: freq) {
            ans += d * f;
        }

        return ans;
    }
};