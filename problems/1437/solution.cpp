class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        stack<int> st;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            if (!st.empty()) {
                if (i - st.top() - 1 < k) {
                    return false;
                }
                
                st.pop();
            }
            
            st.push(i);
        }
        
        return true;
    }
};