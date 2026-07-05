class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (not rows) {
            return "";
        }

        int n = size(encodedText),
            cols = n / rows;
        string ans;

        for (int i = 0; i < cols; i++) {
            int j = 0, k = i;

            while (j < rows and k < cols) {
                ans += encodedText[j * cols + k];
                j++;
                k++;
            }
        }

        while (not empty(ans) and ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};