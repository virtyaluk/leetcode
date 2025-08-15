class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int ans = 0;

        for (const int& aa: a) {
            for (const int& bb: b) {
                for (const int& cc: c) {
                    ans += popcount((uint) aa ^ bb ^ cc) % 2 == 0;
                }
            }
        }

        return ans;
    }
};