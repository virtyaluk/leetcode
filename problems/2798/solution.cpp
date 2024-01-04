class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        
        for (const int& num: hours) {
            ans += num >= target;
        }
        
        return ans;
    }
};