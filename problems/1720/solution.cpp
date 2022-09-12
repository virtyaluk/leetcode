class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans = {first};
        
        for (int& num: encoded) {
            ans.push_back(ans.back() ^ num);
        }
        
        return ans;
    }
};