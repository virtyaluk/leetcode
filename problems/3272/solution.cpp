class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long ans = 0,
            palInt;
        int base = pow(10, (n - 1) / 2),
            skip = n & 1;
        string s;
        unordered_set<string> us;
        vector<long long> factorial(n + 1, 1);

        for (int i = base; i < base * 10; i++) {
            s = to_string(i);
            s += string(rbegin(s) + skip, rend(s)); 
            palInt = stoll(s);

            if (palInt % k == 0) {
                sort(begin(s), end(s));
                us.insert(s);
            }
        }

        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        for (const string& s: us) {
            vector<int> freq(10);

            for (const char& ch: s) {
                freq[ch - '0']++;
            }

            long long tot = (n - freq[0]) * factorial[n - 1];

            for (const int& x: freq) {
                tot /= factorial[x];
            }

            ans += tot;
        }

        return ans;
    }
};