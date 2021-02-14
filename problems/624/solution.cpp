class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxNum = arrays.front().back(), minNum = arrays.front().front(), ans = 0;
        
        for (int i = 1; i < arrays.size(); i++) {
            ans = max(ans, max(abs(arrays[i].back() - minNum), abs(maxNum - arrays[i].front())));
            maxNum = max(maxNum, arrays[i].back());
            minNum = min(minNum, arrays[i].front());
        }
        
        return ans;
    }
};