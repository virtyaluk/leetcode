class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = size(arr), ones = accumulate(begin(arr), end(arr), 0);
        
        if (not ones) {
            return {0, n - 1};
        }
        
        if (ones % 3 != 0) {
            return {-1, -1};
        }
        
        int oneThird = ones / 3, firstIdx = 0, secondIdx = 0, thirdIdx = 0;
        
        for (int i = 0, count = 0; i < n; i++) {
            count += arr[i];
            
            if (arr[i] == 1) {
                if (count == 1) {
                    firstIdx = i;
                } else if (count == oneThird + 1) {
                    secondIdx = i;
                } else if (count == 2 * oneThird + 1) {
                    thirdIdx = i;
                }
            }
        }
        
        for (; thirdIdx < n; firstIdx++, secondIdx++, thirdIdx++) {
            if (arr[firstIdx] != arr[secondIdx] or arr[secondIdx] != arr[thirdIdx]) {
                return {-1, -1};
            }
        }
        
        return {firstIdx - 1, secondIdx};
    }
};