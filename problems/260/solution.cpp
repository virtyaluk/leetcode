class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0, dif = 1, a = 0, b = 0;
        
        for (const int& num: nums) {
            mask ^= num;
        }
        
        while ((mask & dif) == 0) {
            dif <<= 1;
        }
        
        for (const int& num: nums) {
            if ((dif & num) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        
        return {a, b};
    }
    
    /*
    1 - 1
    2 - 10
    3 - 11
    4 = 100
    mask = 5 = 101
    dif = mask & -mask = 5 & -5 = 1
    */
    
    vector<int> singleNumber1(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for (const int& num: nums) {
            m[num]++;
        }
        
        for (auto [num, freq]: m) {
            if (freq == 1) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};