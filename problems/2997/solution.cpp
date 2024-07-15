using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, unsigned int k) {
        for (const int& num: nums) {
            k ^= num;
        }
        
        return popcount(k);
    }
};