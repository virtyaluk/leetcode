class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";

        for (int i = 1; i < size(caption); i++) {
            if (caption[i] == ' ') {
                continue;
            }

            if (caption[i - 1] == ' ') {
                caption[i] = toupper(caption[i]);
            }

            if (caption[i] >= 'A' and caption[i] <= 'Z' and caption[i - 1] != ' ') {
                caption[i] = tolower(caption[i]);
            }
        }

        for (const char& ch: caption) {
            if (ch == ' ') {
                continue;
            }

            ans.push_back(ch);
        }

        ans[1] = tolower(ans[1]);

        return ans.substr(0, 100);
    }
};