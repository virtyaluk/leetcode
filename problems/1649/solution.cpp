const int MOD = 1e9 + 7;

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) {
        n = _n;
        tree.resize(n, 0);
    }
    
    void update(int i, int val) {
        for (; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }
    
    int query(int i) {
        int sum = 0;
        
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        
        return sum;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int ans = 0, n = instructions.size();
        BIT *bit = new BIT(100002);
        
        for (int i = 0; i < n; i++) {
            int lsum = bit->query(instructions[i] - 1), rsum = i - bit->query(instructions[i]);
            
            ans += min(lsum, rsum);
            ans %= MOD;
            
            bit->update(instructions[i], 1);
        }
        
        return ans % MOD;
    }
};