class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans, all;

        for (const char& ch: s) {
            if (ch != '-') {
                all.push_back(toupper(ch));
            }
        }

        int n = size(all),
            firstGroup = n % k == 0 ? k : n % k;
        ans = all.substr(0, firstGroup);

        for (int i = firstGroup; i < n; i += k) {
            ans.push_back('-');
            ans.append(all.substr(i, k));
        }

        return ans;
    }
};