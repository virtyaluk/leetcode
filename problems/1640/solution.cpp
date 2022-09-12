class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        
        while (i < arr.size()) {
            int found = -1;
            
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == arr[i]) {
                    found = j;
                    break;
                }
            }
            
            if (found == -1) {
                return false;
            }
            
            for (int& num: pieces[found]) {
                if (num != arr[i]) {
                    return false;
                }
                
                i++;
            }
        }
        
        return true;
    }
};