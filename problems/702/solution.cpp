/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 10000, notFound = 2147483647;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int got = reader.get(mid);
            
            if (got == notFound) {
                hi = mid;
            } else if (got == target) {
                return mid;
            } else if (target > got) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return -1;
    }
};