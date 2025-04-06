class Solution {
private:
    bool isVowel(const char& ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }

    long long atLeastK(string& s, int k) {
        long long ans = 0;
        unordered_map<char, int> freq;

        for (int lo = 0, hi = 0, cur = 0; hi < size(s);) {
            const char& ch = s[hi];

            if (isVowel(ch)) {
                freq[ch]++;
            } else {
                cur++;
            }

            while (size(freq) == 5 and cur >= k) {
                ans += size(s) - hi;
                char startCh = s[lo];

                if (isVowel(startCh)) {
                    if (not --freq[startCh]) {
                        freq.erase(startCh);
                    }
                } else {
                    cur--;
                }

                lo++;
            }

            hi++;
        }

        return ans;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};