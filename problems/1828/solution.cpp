class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (const vector<int>& q: queries) {
            ans.push_back(0);
            
            for (const vector<int>& p: points) {
                ans.back() += check(q, p);
            }
        }
        
        return ans;
    }
    
    bool check(const vector<int>& c, const vector<int>& p) {
        return pow(c[0] - p[0], 2) + pow(c[1] - p[1], 2) <= c[2] * c[2];
    }
};