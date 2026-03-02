class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = size(mat.front()),
            ans = 0;
        vector<int> heights(n);

        for (const vector<int>& row: mat) {
            for (int i = 0; i < n; i++) {
                heights[i] = (row[i] == 0) ? 0 : heights[i] + 1;
            }

            stack<vector<int>> st;

            st.push({-1, 0, -1});

            for (int i = 0; i < n; i++) {
                int h = heights[i];

                while (st.top()[2] >= h) {
                    st.pop();
                }

                auto& top = st.top();
                int j = top.front(),
                    prev = top[1],
                    cur = prev + (i - j) * h;
                
                st.push({i, cur, h});

                ans += cur;
            }
        }

        return ans;
    }
};