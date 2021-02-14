class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0 or empty(st)) {
                st.push(asteroids[i]);
            } else {
                while (not empty(st) and st.top() > 0 and st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                
                if (not empty(st) and st.top() == abs(asteroids[i])) {
                    st.pop();
                } else if (empty(st) or st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }
        
        while(not empty(st)) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};