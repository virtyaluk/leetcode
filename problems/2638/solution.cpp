class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        long long pick = 0,
            skip = 0;
        int prevNum = -k;
        unordered_map<int, set<int>> cnt;
        
        for (const int& num: nums) {
            cnt[num % k].insert(num);
        }
        
        for (auto& [_, subset]: cnt) {
            for (const int& num: subset) {
                long long tmp = skip;
                skip += pick;
                pick = 1 + tmp + (num - prevNum == k ? 0 : pick);
                prevNum = num;
            }
        }
        
        return 1 + pick + skip;
    }
};