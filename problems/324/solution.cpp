class Solution {
public:
    void wiggleSort1(vector<int>& nums) {
        int n = size(nums), j = n - 1;
        vector<int> arr(begin(nums), end(nums));
        
        sort(begin(arr), end(arr));
        
        for (int i = 1; i < n; i += 2) {
            nums[i] = arr[j--];
        }
        
        for (int i = 0; i < n; i += 2) {
            nums[i] = arr[j--];
        }
    }
    
    void wiggleSort(vector<int>& nums) {
        int n = size(nums), mid;
        auto median = begin(nums) + n / 2;
        auto mapIdx = [n](int i) {
            return (1 + 2 * i) % (n | 1);
        };
        
        nth_element(begin(nums), median, end(nums));
        
        mid = *median;
        
        for (int lo = 0, hi = n - 1, i = 0; i <= hi;) {
            if (nums[mapIdx(i)] > mid) {
                swap(nums[mapIdx(i++)], nums[mapIdx(lo++)]);
            } else if (nums[mapIdx(i)] < mid) {
                swap(nums[mapIdx(i)], nums[mapIdx(hi--)]);
            } else {
                i++;
            }
        }
    }
};