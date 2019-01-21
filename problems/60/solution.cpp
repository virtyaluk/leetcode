class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums;
        int fact = 1,
            curNum = n;
        k--;
        
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            fact *= i;
        }
        
        for (int i = 1; i<= n; i++) {
            fact /= curNum--;
            
            int idx = k / fact;
            ans.push_back('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact;
        }
        
        return ans;
    }
    
    string getPermutation2(int n, int k) {
        vector<string> permutations;
        vector<bool> used(n + 1);
        
        backtrack(n, k, permutations, used, string(""));
        
        return permutations[k - 1];
    }
    
    void backtrack(int n, int k, vector<string>& permutations, vector<bool>& used, string candidate) {
        if (permutations.size() == k) {
            return;
        }
        
        if (candidate.size() == n) {
            permutations.push_back(candidate);
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (not used[i]) {
                candidate.push_back(i + '0');
                used[i] = true;
                
                backtrack(n, k, permutations, used, candidate);
                
                candidate.pop_back();
                used[i] = false;
            }
        }
    }
    
    string getPermutation1(int n, int k) {
        vector<int> ans(n);
        iota(begin(ans), end(ans), 1);
        
        for (int i = 0; i < k - 1; i++) {
            next_permutation(begin(ans), end(ans));
        }
        
        return accumulate(begin(ans), end(ans), string(""), [](const string& cur, const int& next) {
            return cur + to_string(next);
        });
    }
};