class Solution {
public:
    static int lcm(const int x, const int y) {
        return x / gcd(x, y) * y;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;

        for (const int& num: nums) {
            int cur = num;

            while (size(ans)) {
                int g = gcd(ans.back(), cur);

                if (g == 1) {
                    break;
                }

                cur = lcm(ans.back(), cur);
                ans.pop_back();
            }

            ans.push_back(cur);
        }

        return ans;
    }
};