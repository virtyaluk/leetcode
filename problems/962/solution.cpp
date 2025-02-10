class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        
        for (int i = 0; i < size(nums); i++) {
            if (empty(st) or nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        
        for (int j = size(nums) - 1; j >= 0; j--) {
            while (not empty(st) and nums[st.top()] <= nums[j]) {
                ans = max(ans, j - st.top());
                
                st.pop();
            }
        }
        
        return ans;
    }
};