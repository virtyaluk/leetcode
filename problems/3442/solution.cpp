class Solution {
public:
    int maxDifference(string s) {
        int maxOdd = INT_MIN,
            minEven = INT_MAX;
        unordered_map<char, int> um;

        for (const char& ch: s) {
            um[ch]++;
        }

        for (auto [_, freq]: um) {
            if (freq % 2 == 0) {
                minEven = min(minEven, freq);
            } else {
                maxOdd = max(maxOdd, freq);
            }
        }

        return maxOdd - minEven;
    }
};