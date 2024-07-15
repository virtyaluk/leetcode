class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = size(heights);
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = size(heights) - 1; i >= 0; i--) {
            int cnt = 0;
            
            while (not empty(st) and st.top() < heights[i]) {
                st.pop();
                cnt++;
            }
            
            ans[i] = cnt + not empty(st);
            st.push(heights[i]);
        }
        
        return ans;
    }
};