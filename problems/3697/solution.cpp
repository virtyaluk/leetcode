class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;

        for (long long m = 1; n > 0; m *= 10) {
            int d = n % 10;
            n /= 10;

            if (not d) {
                continue;
            }
    
            ans.push_back(d * m);
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};