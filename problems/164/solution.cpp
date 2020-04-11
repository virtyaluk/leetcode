class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int ans = 0,
            minNum = *min_element(begin(nums), end(nums)),
            maxNum = *max_element(begin(nums), end(nums));
        int prevBucketMax = minNum,
            bucketSize = max(1, (maxNum - minNum) / ((int) nums.size()));
        vector<tuple<bool, int, int>> buckets((maxNum - minNum) / bucketSize + 1, {false, INT_MAX, INT_MIN});
        
        for (const int& num: nums) {
            int bucketIdx = (num - minNum) / bucketSize;
            
            get<0>(buckets[bucketIdx]) = true;
            get<1>(buckets[bucketIdx]) = min(get<1>(buckets[bucketIdx]), num);
            get<2>(buckets[bucketIdx]) = max(get<2>(buckets[bucketIdx]), num);
        }
        
        for (auto &[used, bucketMin, bucketMax]: buckets) {
            if (not used) {
                continue;
            }
            
            ans = max(ans, bucketMin - prevBucketMax);
            prevBucketMax = bucketMax;
        }
        
        return ans;
    }
    
    int maximumGap1(vector<int>& nums) {
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        
        return ans;
    }
};