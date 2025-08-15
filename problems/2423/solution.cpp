class Solution {
private:
    bool check(vector<int>& freq) {
        int posFreq = -1;

        for (const int& f: freq) {
            if (f) {
                if (posFreq == -1) {
                    posFreq = f;
                } else if (f == posFreq) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool equalFrequency(string word) {
        vector<int> freq(26);

        for (const char& ch: word) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                freq[i]--;

                if (check(freq)) {
                    return true;
                }

                freq[i]++;
            }
        }

        return false;
    }
};