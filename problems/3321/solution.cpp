class OS {
private:
    int x;
    long long ans;
    set<pair<int, int>> large, small;
    unordered_map<int, int> occ;

    void _insert(const pair<int, int>& p) {
        if (size(large) < x or p > *begin(large)) {
            ans += static_cast<long long>(p.first) * p.second;

            large.insert(p);

            if (size(large) > x) {
                ans -= static_cast<long long>(begin(large)->first) * begin(large)->second;
                auto transfer = *begin(large);
                
                large.erase(transfer);
                small.insert(transfer);
            }
        } else {
            small.insert(p);
        }
    }

    void _remove(const pair<int, int>& p) {
        if (p >= *begin(large)) {
            ans -= static_cast<long long>(p.first) * p.second;

            large.erase(p);

            if (not empty(small)) {
                ans += static_cast<long long>(rbegin(small)->first) * rbegin(small)->second;
                auto transfer = *rbegin(small);
                
                small.erase(transfer);
                large.insert(transfer);
            }
        } else {
            small.erase(p);
        }
    }

public:
    OS(int x) {
        this->x = x;
        this->ans = 0;
    }

    void insert(int num) {
        if (occ[num]) {
            _remove({occ[num], num});
        }

        occ[num]++;

        _insert({occ[num], num});
    }

    void remove(int num) {
        _remove({occ[num], num});

        occ[num]--;

        if (occ[num]) {
            _insert({occ[num], num});
        }
    }

    long long get() {
        return ans;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        OS os(x);

        for (int i = 0; i < size(nums); i++) {
            os.insert(nums[i]);

            if (i >= k) {
                os.remove(nums[i - k]);
            }

            if (i >= k - 1) {
                ans.push_back(os.get());
            }
        }

        return ans;
    }
};