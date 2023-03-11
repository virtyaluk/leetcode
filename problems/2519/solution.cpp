class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int ans = 0, n = size(nums);
        vector<bool> lv(n), rv(n);
        priority_queue<int> left, right;
        
        for (int i = 0; i < k; i++) {
            left.push(nums[i]);
            right.push(nums[n - i - 1]);
        }
        
        for (int i = k; i < n - k; i++) {
            lv[i] = left.top() < nums[i];
            rv[n - i - 1] = right.top() < nums[n - i - 1];
            
            left.push(nums[i]);
            left.pop();
            right.push(nums[n - i - 1]);
            right.pop();
        }
        
        for (int i = k; i < n - k; i++) {
            ans += lv[i] and rv[i];
        }
        
        return ans;
    }
};