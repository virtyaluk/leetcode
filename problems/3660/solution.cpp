class Solution {
private:
    struct Item {
        int value, left, right;
    };
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = size(nums);
        vector<int> ans(n);
        vector<Item> stack;

        for (int i = 0; i < n; i++) {
            Item curr = {nums[i], i, i};

            while (not empty(stack) and stack.back().value > nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }

            stack.push_back(curr);
        }

        for (int i = 0; i < size(stack); i++) {
            for (int j = stack[i].left; j <= stack[i].right; j++) {
                ans[j] = stack[i].value;
            }
        }

        return ans;
    }
};