class Solution {
private:
//     int my_rand(int lo, int hi) {
//         random_device rd;
//         mt19937 gen(rd());
//         uniform_int_distribution<> distrib(lo, hi);
        
//         return distrib(gen);
//     }
    
//     int my_rand2(int lo, int hi) {
//         return rand() % (hi - lo + 1) + lo;
//     }
    
//     unordered_map<int, vector<int>> idx;
    vector<int> nums;

public:
    Solution(vector<int>& nums): nums{nums} {}
    
    int pick(int target) {
        int ans = 0, count = 0;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == target) {
                count++;
                
                if (rand() % count == 0) {
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};

// class Solution {
// private:
//     int my_rand(int lo, int hi) {
//         random_device rd;
//         mt19937 gen(rd());
//         uniform_int_distribution<> distrib(lo, hi);
        
//         return distrib(gen);
//     }
    
//     int my_rand2(int lo, int hi) {
//         return rand() % (hi - lo + 1) + lo;
//     }
    
//     unordered_map<int, vector<int>> idx;

// public:
//     Solution(vector<int>& nums) {
//         for (int i = 0; i < size(nums); i++) {
//             idx[nums[i]].push_back(i);
//         }
//     }
    
//     int pick(int target) {
//         int bucketSize = size(idx[target]);
        
//         return idx[target][rand() % bucketSize];
//     }
// };

// /**
//  * Your Solution object will be instantiated and called as such:
//  * Solution* obj = new Solution(nums);
//  * int param_1 = obj->pick(target);
//  */