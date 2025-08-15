class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = INT_MAX;
        unordered_map<char, int> um1,
            um2;

        for (const char& ch: s) {
            um1[ch]++;
        }

        for (const char& ch: target) {
            um2[ch]++;
        }

        for (auto [ch, freq]: um2) {
            ans = min(ans, um1[ch] / freq);
        }

        return ans;
    }
};