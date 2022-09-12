class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = size(cars);
        vector<double> ans(n, -1);
        vector<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (not empty(st) and cars[st.back()][1] >= cars[i][1]) {
                st.pop_back();
            }
            
            for (auto j = rbegin(st); j != rend(st); j++) {
                if (ans[*j] == -1 or catchTime(cars, i, *j) <= ans[*j]) {
                    ans[i] = catchTime(cars, i, *j);
                    break;
                }
            }
            
            st.push_back(i);
        }
        
        return ans;
    }
    
    double catchTime(vector<vector<int>>& cars, int i, int j) {
        double pos = cars[j][0] - cars[i][0],
            speed = cars[i][1] - cars[j][1];
        
        return pos / speed;
    }
};