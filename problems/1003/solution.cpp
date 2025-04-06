class Solution {
public:
    bool isValid(string s) {
        string ans;

        for (const char& ch: s) {
            ans.push_back(ch);

            if (size(ans) >= 3 and ans[size(ans) - 1] == 'c' and ans[size(ans) - 2] == 'b' and ans[size(ans) - 3] == 'a') {
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            }
        }

        return empty(ans);
    }
};