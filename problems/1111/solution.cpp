class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq, int depth = 0) {
        vector<int> ans;
        
        for (const char& ch: seq) {
            if (ch == '(') {
                ans.push_back(++depth % 2);
            } else {
                ans.push_back(depth-- % 2);
            }
        }
        
        return ans;
    }
};