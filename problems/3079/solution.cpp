class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, [](const int& accum, const int& cur) {
            string snum = to_string(cur);
            return accum + stoi(string(size(snum), *max_element(begin(snum), end(snum))));
        });
    }
};