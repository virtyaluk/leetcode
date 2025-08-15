class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> um;

        for (int i = 0; i < size(nums); i++) {
            um[nums[i]] = i;
        }

        for (const vector<int>& op: operations) {
            nums[um[op[0]]] = op[1];
            um[op[1]] = um[op[0]];
        }

        return nums;
    }
};