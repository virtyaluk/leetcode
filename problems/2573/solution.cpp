class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = size(lcp);
        string word(n, '\0');
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (cur > 'z') {
                    return "";
                }

                word[i] = cur;

                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }

                cur++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 or j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return word;
    }
};