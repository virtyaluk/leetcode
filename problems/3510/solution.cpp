typedef long long ll;

const int MAX_N = 100005;

struct Node {
    ll value;
    int left;
};

using ListIt = list<Node>::iterator;

struct Pair {
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi),
          second(se),
          firstLeft(fi->left),
          secondLeft(se->left),
          cost(cost) {}
};

struct ComparePair {
    bool operator()(const Pair& a, const Pair& b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        }

        return a.firstLeft > b.firstLeft;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        list<Node> list;
        bitset<MAX_N> merged;
        priority_queue<Pair, vector<Pair>, ComparePair> pq;

        int decreaseCount = 0;
        int count = 0;

        list.push_back({nums[0], 0});

        for (int i = 1; i < size(nums); ++i) {
            list.push_back({nums[i], (int)i});

            auto curr = prev(end(list));
            auto pr = prev(curr);

            pq.push({pr, curr, pr->value + curr->value});

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0 and not empty(pq)) {
            auto top = pq.top();
            pq.pop();

            if (merged[top.firstLeft] || merged[top.secondLeft]) {
                continue;
            }

            auto first = top.first;
            auto second = top.second;
            auto cost = top.cost;

            if (first->value + second->value != cost) {
                continue;
            }

            count++;

            if (first->value > second->value) {
                decreaseCount--;
            }

            ListIt pr =
                (first == begin(list)) ? end(list) : prev(first);
            ListIt nx = next(second);

            if (pr != end(list)) {
                if (pr->value > first->value and pr->value <= cost) {
                    decreaseCount--;
                }

                if (pr->value <= first->value and pr->value > cost) {
                    decreaseCount++;
                }

                pq.push({pr, first, pr->value + cost});
            }

            if (nx != end(list)) {
                if (second->value > nx->value and cost <= nx->value) {
                    decreaseCount--;
                }

                if (second->value <= nx->value and cost > nx->value) {
                    decreaseCount++;
                }

                pq.push({first, nx, cost + nx->value});
            }

            first->value = cost;
            merged[second->left] = 1;
            list.erase(second);
        }

        return count;
    }
};