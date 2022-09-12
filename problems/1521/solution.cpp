class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> s;
        int ans = INT_MAX;
        
        for (const int& num: arr) {
            unordered_set<int> s1;
            s1.insert(num);
            
            for (const int& num1: s) {
                s1.insert(num1 & num);
            }
            
            for (const int& num1: s1) {
                ans = min(ans, abs(num1 - target));
            }
            
            s = s1;
        }
        
        return ans;
    }
};