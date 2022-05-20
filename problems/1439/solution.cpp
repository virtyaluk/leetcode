class Solution {
private:
    vector<int> helper(const vector<int>& nums1, const vector<int>& nums2, int k) {
        vector<int> ans;
        int m = size(nums1),
            n = size(nums2);
        auto cmp = [nums1, nums2](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        if (not m or not n) {
            return ans;
        }
        
        pq.push({0, 0});
        
        while (k-- and not empty(pq)) {
            auto [i, j] = pq.top();
            pq.pop();
            
            
            if (j + 1 < n) {
                pq.push({i, j + 1});
            }
            
            if (not j and i + 1 < m) {
                pq.push({i + 1, j});
            }
            
            ans.push_back(nums1[i] + nums2[j]);
        }
        
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> nums1 = mat.front();
        int n = size(mat);
        
        for (int i = 1; i < n; i++) {
            nums1 = helper(nums1, mat[i], k);
        }
        
        return nums1[k - 1];
    }
};