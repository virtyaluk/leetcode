class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<string> temp;
        vector<int> r,
            ans;
        vector<pair<int,int>> v;
        int n = size(nums);
        
        for (int i = 0; i < n; i++) {
            string s = "";
            int num = nums[i];

            while (num > 0) {
                s = s + to_string(num % 2);
                num = num / 2;
            }

            temp.push_back(s);
        }

        for (string s: temp) {
            r.push_back(stoi(s, 0, 2));
        }
    
        for (int i = 0; i < n; i++) {
            v.push_back({r[i], nums[i]});
        }

        sort(begin(v), end(v));

        for (int i = 0; i < n; i++) {
            ans.push_back({v[i].second});
        }

        return ans;        
    }
};