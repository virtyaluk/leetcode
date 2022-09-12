class SparseVector {
public:
    vector<pair<int, int>> pairs;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != 0) {
                pairs.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0, i = 0, j = 0, m = size(pairs), n = size(vec.pairs);
        
        while (i < m and j < n) {
            if (pairs[i].first == vec.pairs[j].first) {
                ans += pairs[i].second * vec.pairs[j].second;
                i++;
                j++;
            } else if (pairs[i].first < vec.pairs[j].first) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);