class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int dif = (arr.back() - arr[0]) / n;
        int expected = arr[0];
        
        for (const int& num: arr) {
            if (num != expected) {
                return expected;
            }
            
            expected += dif;
        }
        
        return expected;
    }
};