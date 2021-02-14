class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = size(t);
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (not st.empty() and t[st.top()] <= t[i]) {
                st.pop();
            }
            
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = size(temperatures);
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        
        return ans;
    }
};