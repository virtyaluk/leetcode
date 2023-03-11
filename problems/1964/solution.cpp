class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = size(obstacles);
        vector<int> ans(n, 1), lis;
        
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(begin(lis), end(lis), obstacles[i]) - begin(lis);
            
            if (idx == size(lis)) {
                lis.push_back(obstacles[i]);
            } else {
                lis[idx] = obstacles[i];
            }
            
            ans[i] = idx + 1;
        }
        
        return ans;
    }
};