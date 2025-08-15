class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        for (int i = 1; i < size(word); i++) {
            ans += word[i] == word[i - 1];
        }

        return ans;
    }
};