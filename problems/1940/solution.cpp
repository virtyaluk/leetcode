class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> freq;
        vector<int> ans;
        
        for (const vector<int>& array: arrays) {
            for (const int& num: array) {
                if (++freq[num] == size(arrays)) {
                    ans.push_back(num);
                }
            }
        }
        
        return ans;
    }
};