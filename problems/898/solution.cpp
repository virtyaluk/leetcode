class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans,
            cur {0};
        
        for (const int& num: arr) {
            unordered_set<int> cur2;

            for (int num2: cur) {
                cur2.insert(num | num2);
            }

            cur2.insert(num);
            cur = cur2;
            ans.insert(begin(cur), end(cur));
        }
        
        return size(ans);
    }
};