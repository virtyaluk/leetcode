class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        if (size(arr) <= 2) {
            return arr;
        }
        
        while (true) {
            vector<int> nextArr(begin(arr), end(arr));
            
            for (int i = 1; i < size(arr) - 1; i++) {
                if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
                    nextArr[i]--;
                }
                
                if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1]) {
                    nextArr[i]++;
                }
            }
            
            if (arr == nextArr) {
                return arr;
            }
            
            arr = nextArr;
        }
        
        return arr;
    }
};