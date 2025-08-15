class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = size(word);
        unordered_map<char, int> um;

        for (const char& ch: word) {
            um[ch]++;
        }

        for (auto [_, a]: um) {
            int del = 0;

            for (auto [_, b]: um) {
                if (a > b) {
                    del += b;
                } else if (b > a + k) {
                    del += b - (a + k);
                }
            }

            ans = min(ans, del);
        }

        return ans;
    }
};