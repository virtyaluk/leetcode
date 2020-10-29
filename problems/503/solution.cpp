class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(size(nums));
        stack<int> st;
        
        for (int i = size(nums) - 1; i >= 0; i--) {
            st.push(nums[i]);
        }
        
        for (int i = size(nums) - 1; i >= 0; i--) {
            while (not empty(st) and st.top() <= nums[i]) {
                st.pop();
            }
            
            ans[i] = empty(st) ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return ans;
    }
};