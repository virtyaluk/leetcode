const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power,
            binary,
            ans;

        while (n > 0) {
            binary.push_back(n % 2);
            n /= 2;
        }

        for (int i = 0; i < size(binary); i++) {
            if (binary[i]) {
                power.push_back(binary[i] * pow(2, i));
            }
        }

        for (const vector<int>& q: queries) {
            int l = q.front(),
                r = q.back();
            long long t = 1;

            for (int i = l; i <= r; i++) {
                t *= power[i];
                t %= MOD;
            }

            ans.push_back(t);
        }
        
        return ans;
    }
};