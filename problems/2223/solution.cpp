class Solution {
private:
    void helper(vector<long long>& lps, string& s) {
        long long m = size(s),
            len = 0,
            i = 1;
        lps[0] = 0;

        while (i < m) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    long long sumScores(string s) {
        long long n = size(s);
        vector<long long> lps(n);
        vector<int> ans;

        helper(lps, s);

        for (auto num: lps) {
            ans.push_back((num == 0) ? 0 : ans[num - 1] + 1);
        }

        return accumulate(begin(ans), end(ans), 0ll) + size(s);
    }
};