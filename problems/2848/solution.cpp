class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;
        vector<int> line(102, 0);
        
        for (const vector<int>& num: nums) {
            line[num.front()]++;
            line[num.back() + 1]--;
        }
        
        for (int i = 0, sum = 0; i < 102; i++) {
            sum += line[i];
            ans += sum > 0;
        }
        
        return ans;
    }
};