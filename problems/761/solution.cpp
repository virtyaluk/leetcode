class Solution {
public:
    string makeLargestSpecial(string s) {
        string ans;
        vector<string> p;

        for (int lo = 0, hi = 0, bal = 0; hi < size(s); hi++) {
            if (s[hi] == '0') {
                bal--;
            } else {
                bal++;
            }

            if (not bal) {
                p.push_back("1" + makeLargestSpecial(s.substr(lo + 1, hi - lo - 1)) + "0");
                lo = hi + 1;
            }
        }

        sort(begin(p), end(p), greater<string>());

        for (auto& pp: p) {
            ans += pp;
        }

        return ans;
    }
};