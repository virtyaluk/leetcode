class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        
        st.push(0);
        
        for (int i = 1; i < size(nums); i++) {
            while (not empty(st) and nums[st.top()] > nums[i]) {
                ans += i - st.top();
                st.pop();
            }
            
            st.push(i);
        }
        
        int last = empty(st) ? -1 : st.top();
        
        while (not empty(st)) {
            ans += last - st.top() + 1;
            st.pop();
        }
        
        return ans;
    }
};