class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int sum = 0, i = 0;
        
        while (sum <= size(grades)) {
            sum += ++i;
        }
        
        return i - 1;
    }
};