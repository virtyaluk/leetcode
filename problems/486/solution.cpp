class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, size(nums) - 1, 1) >= 0;
    }
    
    int dfs(const vector<int>& nums, int lo, int hi, int turn) {
        if (lo == hi) {
            return turn * nums[lo];
        }
        
        int first = turn * nums[lo] + dfs(nums, lo + 1, hi, -turn),
            second = turn * nums[hi] + dfs(nums, lo, hi - 1, -turn);
        
        return turn * max(turn * first, turn * second);
    }
};