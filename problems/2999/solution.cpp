class Solution {
private:
    long long helper(string x, string s, const int& limit) {
        if (size(x) < size(s)) {
            return 0;
        }

        if (size(x) == size(s)) {
            return x >= s ? 1 : 0;
        }

        long long ans = 0;
        string suffix = x.substr(size(x) - size(s), size(s));
        int len = size(x) - size(s);

        for (int i = 0; i < len; i++) {
            if (limit < (x[i] - '0')) {
                ans += (long) pow(limit + 1, len - i);

                return ans;
            }

            ans += (long) (x[i] - '0') * (long) pow(limit + 1, len - 1 - i);
        }

        if (suffix >= s) {
            ans++;
        }

        return ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st = to_string(start - 1),
            fin = to_string(finish);
        
        return helper(fin, s, limit) - helper(st, s, limit);
    }
};