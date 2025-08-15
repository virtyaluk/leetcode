class Solution {
public:
    int maxFreqSum(string s) {
        int a = 0,
            b = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> um;

        for (const char& ch: s) {
            um[ch]++;

            if (vowels.count(ch)) {
                a = max(a, um[ch]);
            } else {
                b = max(b, um[ch]);
            }
        }

        return a + b;
    }
};