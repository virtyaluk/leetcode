class NumArray {
private:
    int n;
    vector<int> tree, nums;

public:
    NumArray(vector<int>& nums): nums{nums} {
        n = size(nums);
        tree.assign(n + 1, 0);
        
        for (int j = 1; j <= n; j++) {
            tree[j] += nums[j - 1];
            
            if (j + (j & -j) <= n) {
                tree[j + (j & -j)] += tree[j];
            }
        }
    }
    
    void update(int index, int val) {
        int dif = val - nums[index];
        nums[index] = val;
        index++;
        
        while (index <= n) {
            tree[index] += dif;
            index += index & -index;
        }
    }
    
    int getSum(int i) {
        int ans = 0;
        i++;
        
        while (i > 0) {
            ans += tree[i];
            i -= i & -i;
        }
        
        return ans;
    }
    
    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 
 
class NumArray {
private:
    inline static int n;
    vector<int> arr, tree;
    // int *tree;
    
    void build(int node, int lo, int hi) {
        if (lo == hi) {
            tree[node] = arr[lo];
        } else {
            int mid = (lo + hi) / 2;
            
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);
            
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    void upd(int idx, int val, int node = 1, int lo = 0, int hi = n - 1) {
        if (idx < lo or idx > hi) {
            return;
        }
        
        if (lo == hi) {
            if (lo == idx) {
                tree[node] = val;
            }
        } else {
            int mid = (lo + hi) / 2;
            
            if (idx <= mid) {
                upd(idx, val, 2 * node, lo, mid);
            } else {
                upd(idx, val, 2 * node + 1, mid + 1, hi);
            }
            
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    int query(int l, int r, int node = 1, int lo = 0, int hi = n - 1) {
        if (l > hi or r < lo) {
            return 0;
        }
        
        if (l <= lo and r >= hi) {
            return tree[node];
        }
        
        int mid = (lo + hi) / 2;
        int p1 = query(l, r, 2 * node, lo, mid),
            p2 = query(l, r, 2 * node + 1, mid + 1, hi);
        
        return p1 + p2;
    }
public:
    NumArray(vector<int>& nums): arr{nums} {
        n = nums.size();
        tree.assign(4 * n, 0);
        // tree = (int*)malloc(4 * n * sizeof(int));
        
        build(1, 0, n - 1);
    }
    
    void update(int index, int val) {
        upd(index, val);
    }
    
    int sumRange(int left, int right) {
        return query(left, right);
    }
};

 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */