class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        deque<int> p(m); iota(begin(p), end(p), 1);
        
        for (const int& q: queries) {
            auto it = find(begin(p), end(p), q);
            int dist = distance(begin(p), it);
            
            p.erase(it);
            p.push_front(q);
            
            ans.push_back(dist);
        }
        
        return ans;
    }
};