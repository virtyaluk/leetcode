class Solution {
private:
    int xsum(const unordered_map<int, int>& freq, int x) {
        priority_queue<pair<int, int>> pq;
                int sum = 0;

        for (const auto& [num, cnt] : freq) {
            pq.push({cnt, num});
        }

        for (int i = 0; i < x and not empty(pq); i++) {
            auto [cnt, num] = pq.top();
            pq.pop();
            
            sum += cnt * num;
        }

        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        int n = size(nums);
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        ans.push_back(xsum(freq, x));

        for (int i = 1; i <= n - k; i++) {
            freq[nums[i - 1]]--;
            
            if (not freq[nums[i - 1]]) {
                freq.erase(nums[i - 1]);
            }

            freq[nums[i + k - 1]]++;

            ans.push_back(xsum(freq, x));
        }
        
        return ans;
    }
};