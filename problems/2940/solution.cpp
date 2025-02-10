class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans(size(queries), -1);
        unordered_map<int, vector<pair<int, int>>> um;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int i = 0; i < size(queries); i++) {
            int a = queries[i].front(),
                b = queries[i].back();
            
            if (a < b and heights[a] < heights[b]) {
                ans[i] = b;
            } else if (a > b and heights[a] > heights[b]) {
                ans[i] = a;
            } else if (a == b) {
                ans[i] = a;
            } else {
                um[max(a, b)].push_back({max(heights[a], heights[b]), i});
            }
        }
        
        for (int i = 0; i < size(heights); i++) {
            while (not empty(pq) and pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            
            for (auto el: um[i]) {
                pq.push(el);
            }
        }
        
        return ans;
    }
};