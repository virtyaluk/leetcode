class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = m, count = 0; i < arr.size(); i++) {
            if (arr[i] != arr[i - m]) {
                count = 0;
            } else if (++count == m * (k - 1)) {
                return true;
            }
        }
        
        return false;
    }
};