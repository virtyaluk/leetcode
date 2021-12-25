class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        for (int i = 0; i < size(arr); i++) {
            if (i == arr[i]) {
                return i;
            }
        }
        
        return -1;
    }
};