/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int lo = 0, hi = reader.length() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int check = (hi - lo) % 2 == 0 ? reader.compareSub(lo, mid, mid, hi) : reader.compareSub(lo, mid, mid + 1, hi);
            
            if (check == 1) {
                hi = mid;
            } else if (check == -1) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        
        return lo;
    }
};