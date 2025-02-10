class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        bitset<128> bs;
        
        for (const int& num: nums) {
            if (bs[num]) {
                ans.push_back(num);
            } else {
                bs[num] = true;
            }
        }
        
        return ans;
    }
};