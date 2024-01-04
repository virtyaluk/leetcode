class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= size(arr)) {
            return *max_element(begin(arr), end(arr));
        }
        
        for (int i = 1, winCount = 0; i < size(arr); i++) {
            if (arr[i] > arr.front()) {
                swap(arr[i], arr.front());
                winCount = 1;
            } else {
                winCount++;
            }
            
            if (winCount >= k) {
                break;
            }
        }
        
        return arr.front();
    }
};