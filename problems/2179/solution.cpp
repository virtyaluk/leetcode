#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0,
            n = size(nums1);
        ordered_set os1, os2;
        map<int, int> m;
        vector<int> vi(n);

        for (int i = 0; i < n; i++) {
            m[nums2[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            vi[i] = size(os1) - os1.order_of_key(m[nums1[i]]);
            os1.insert(m[nums1[i]]);
        }

        for (int i = 0; i < n; i++) {
            int x = os2.order_of_key(m[nums1[i]]);
            ans += 1ll * x * vi[i];

            os2.insert(m[nums1[i]]);
        }

        return ans;
    }
};