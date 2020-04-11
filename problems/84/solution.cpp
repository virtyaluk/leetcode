class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        
        st.push(-1);
        
        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 and heights[st.top()] >= heights[i]) {
                int curHeight = heights[st.top()];
                st.pop();
                
                ans = max(ans, curHeight * (i - st.top() - 1));
            }
            
            st.push(i);
        }
        
        while (st.top() != -1) {
            int curHeight = heights[st.top()];
            st.pop();
            int curWidth = heights.size() - st.top() - 1;
            
            ans = max(ans, curHeight * curWidth);
        }
        
        return ans;
    }
};