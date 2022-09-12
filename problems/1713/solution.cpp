class Solution {
private:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for (const int& num: nums) {
            auto it = lower_bound(begin(dp), end(dp), num);
            
            if (it == end(dp)) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return size(dp);
    }

public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> um;
        vector<int> tar;
        
        for (int i = 0; i < size(target); i++) {
            um[target[i]] = i;
        }
        
        for (const int& num: arr) {
            if (um.count(num)) {
                tar.push_back(um[num]);
            }
        }
        
        return size(target) - lengthOfLIS(tar);
    }
};