class Solution {
public:
    int maximumSwap(int num) {
        int ans = 0;
        string snum = to_string(num);
        vector<int> nums(10, -1);
        
        for (int i = 0; i < size(snum); i++) {
            nums[snum[i] - '0'] = i;
        }
        
        for (int i = 0; i < size(snum); i++) {
            int cur = snum[i] - '0';
            
            for (int j = 9; j > cur; j--) {
                if (nums[j] > i) {
                    swap(snum[i], snum[nums[j]]);
                    
                    return stoi(snum);
                }
            }
        }
        
        return num;
    }
};