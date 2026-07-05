class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int f(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = f(parent[x]);
    }

    bool u(int x, int y) {
        int rx = f(x),
            ry = f(y);
        
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
            } else if (rank[rx] > rank[ry]) {
                parent[ry] = rx;
            } else {
                parent[rx] = ry;
                rank[ry]++;
            }

            return true;
        }

        return false;
    }

    bool isConnected(int x, int y) {
        return f(x) == f(y);
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = size(nums);
        int maxEl = *max_element(begin(nums), end(nums));
        DSU dsu(maxEl);

        for (int num: nums) {
            for (int divisor = 2; divisor * divisor <= num; divisor++) {
                if (num % divisor == 0) {
                    dsu.u(num, divisor);

                    if (divisor != num / divisor) {
                        dsu.u(num, num/divisor);
                    }
                }
            } 
        }

        vector<int> sortedArr(nums);

        sort(begin(sortedArr), end(sortedArr));

        for (int i = 0; i < n; i++) {
            if (not dsu.isConnected(nums[i], sortedArr[i])) {
                return false;
            }
        }

        return true;
    }
};