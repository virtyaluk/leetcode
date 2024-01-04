/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        int ans = 1;
        
        for (long long i = 1; i < nums->size(); i++) {
            if (nums->at(i) != nums->at(i - 1)) {
                ans++;
            }
            
            long long j = 1;
            
            while (i + j < nums->size() and nums->at(i) == nums->at(i + j)) {
                j *= 2;
            }
            
            i += j / 2;
        }
        
        return ans;
    }
};