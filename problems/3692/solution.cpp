class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> um1;
        unordered_map<int, int> um2;
        int bestFreq = 0,
            maxCount = 0;
        string ans;

        for (const char& ch: s) {
            um1[ch]++;
        }

        for (auto [_, freq]: um1) {
            um2[freq]++;
        }

        for (auto& [f, c]: um2) {
            if (c > maxCount or (c == maxCount and f > bestFreq)) {
                bestFreq = f;
                maxCount = c;
            }
        }

        for (auto& [ch, freq]: um1) {
            if (freq == bestFreq) {
                ans += ch;
            }
        }

        return ans;
    }
};