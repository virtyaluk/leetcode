class Solution {
private:
    unordered_set<int> unique_prime_factors(int n) {
        unordered_set<int> factors;
        
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                factors.insert(i);
                n /= i;
            }
        }

        if (n > 1) {
            factors.insert(n);
        }

        return factors;
    }

    void dfs(int i, unordered_set<int>& visited, vector<vector<int>>& g) {
        visited.insert(i);

        for (int u: g[i]) {
            if (visited.find(u) == end(visited)) {
                dfs(u, visited, g);
            }
        }
    }
    
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> g(n);
        unordered_map<int, int> lastIndex;
        unordered_set<int> visited;

        for (int i = 0; i < size(nums); i++) {
            unordered_set<int> primeFactors = unique_prime_factors(nums[i]);

            for (int factor: primeFactors) {
                if (lastIndex.find(factor) != end(lastIndex)) {
                    int prevIndex = lastIndex[factor];
                    g[prevIndex].push_back(i);
                    g[i].push_back(prevIndex);
                }

                lastIndex[factor] = i;
            }
        }

        // set<int> visited;
        dfs(0, visited, g);

        return size(visited) == n;
    }
};