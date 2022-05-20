class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int freq = 0;
        int val = arr[arr.size() - 1];
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == val) {
                freq++;
            } else {
                if (val == freq) {
                    return val;
                }
                
                val = arr[i];
                freq = 1;
            }
        }
        
        return freq == val ? val : -1;
    }
};
