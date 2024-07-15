/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        int ans = n;
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (categoryHandler->haveSameCategory(i, j)) {
                    ans--;
                    break;
                }
            }
        }
        
        return ans;
    }
};