class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        
        for (const int& num: arr1) {
            a ^= num;
        }
        
        for (const int& num: arr2) {
            b ^= num;
        }
        
        return a & b;
    }
};