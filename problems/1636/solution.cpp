class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        sort(begin(nums), end(nums), [&](const int& lhs, const int& rhs) {
            if (um[lhs] == um[rhs]) {
                return lhs > rhs;
            }
            
            return um[lhs] < um[rhs];
        });
        
        return nums;
    }
};