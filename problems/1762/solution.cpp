class Solution {
public:
    vector<int> findBuildings1(vector<int>& heights) {
        vector<int> ans;
        
        for (int i = size(heights) - 1, maxHeight = INT_MIN; i >= 0; i--) {
            if (heights[i] > maxHeight) {
                ans.push_back(i);
            }
            
            maxHeight = max(maxHeight, heights[i]);
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
    
    vector<int> findBuildings(vector<int>& heights) {
        int n = size(heights);
        vector<int> ans = {n - 1};
        
        for (int i = n - 2, maxHeight = heights.back(); i >= 0; i--) {
            if (heights[i] > maxHeight) {
                ans.push_back(i);
            }
            
            maxHeight = max(maxHeight, heights[i]);
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};