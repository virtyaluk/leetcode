class Solution {
private:
    long long seqSum(long long len, int cnt) {
        return (len * (len + 1) - (len > cnt ? (len - cnt) * (len - cnt + 1) : 0)) / 2;
    }
public:
    long long maximumBooks(vector<int>& books) {
        long long cur = 0,
            ans = 0;
        vector<int> stack;
        
        for (int i = 0; i < size(books); i++) {
            while (not empty(stack) and books[i] - books[stack.back()] < i - stack.back()) {
                int j = stack.back();
                stack.pop_back();
                
                cur -= seqSum(books[j], empty(stack) ? j + 1 : j - stack.back());
            }
            
            cur += seqSum(books[i], empty(stack) ? i + 1 : i - stack.back());
            stack.push_back(i);
            ans = max(ans, cur);
        }
        
        return ans;
    }
};