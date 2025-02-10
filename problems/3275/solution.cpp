class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        
        for (const vector<int>& q: queries) {
            pq.push(abs(q.front()) + abs(q.back()));
            
            if (size(pq) > k) {
                pq.pop();
            }
            
            if (size(pq) >= k) {
                ans.push_back(pq.top());
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};