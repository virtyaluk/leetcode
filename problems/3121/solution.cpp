class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(26, -1),
            b(26, -1);
        int ans = 0;

        for (int i = 0; i < size(word); i++) {
            char ch = word[i];

            if (islower(ch)) {
                a[ch - 'a'] = i;
            } else if (b[ch - 'A'] == -1) {
                b[ch - 'A'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            ans += a[i] != -1 and b[i] != -1 and a[i] < b[i];
        }

        return ans;
    }
};