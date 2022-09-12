struct Trie {
    Trie *z = NULL, *o = NULL;
    
    Trie() {}
};

Trie* insert(Trie *node, int k, int num) {
    if (!node) {
        node = new Trie();
    }
    
    if (k < 0) {
        return node;
    }
    
    if (((num >> k) & 1) == 1) {
        node->o = insert(node->o, k - 1, num);
    } else {
        node->z = insert(node->z, k - 1, num);
    }
    
    return node;
}

int query(Trie* node, int k, int num) {
    int ans = 0;
    
    if (k < 0) {
        return ans;
    }
    
    if (((num >> k) & 1) == 1) {
        if (node->z) {
            ans = pow(2, k) + query(node->z, k - 1, num);
        } else {
            ans = query(node->o, k - 1, num);
        }
    } else {
        if (node->o) {
            ans = pow(2, k) + query(node->o, k - 1, num);
        } else {
            ans = query(node->z, k - 1, num);
        }
    }
    
    return ans;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        Trie *trie = new Trie();
        
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [](vector<int>& lhs, vector<int>& rhs) {
           return lhs[1] < rhs[1]; 
        });
        
        for (int i = 0, j = 0; i < queries.size(); i++) {
            int xi = queries[i][0], mi = queries[i][1], idx = queries[i][2];
            
            while (j < nums.size() && nums[j] <= mi) {
                insert(trie, 31, nums[j]);
                j++;
            }
            
            if (j > 0) {
                ans[idx] = query(trie, 31, xi);
            }
        }
        
        return ans;
    }
};