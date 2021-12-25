class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans = {label};
        int height = log2(label);
        
        while (height) {
            int left = pow(2, height - 1),
                right = pow(2, height) - 1;
            
            label = left + (right - label / 2);
            
            ans.push_back(label);
            height--;
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};