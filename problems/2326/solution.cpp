class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
		vector<vector<int>> ans(n, vector<int>(m, -1));
        int i = 0, j = 0;
		
        while (head) {
            if (j < m) {
                while (head and j < m and ans[i][j] == -1) {
                    ans[i][j] = head->val;
                    head = head->next;
                    j++;
                }

                if (not head) {
                    break;
                }

                i++;
                j--;
            }

            if (i < n) {
                while (head and i < n and ans[i][j] == -1) {
                    ans[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }

            if (j >= 0) {
                while (head and j >= 0 and ans[i][j] == -1) {
                    ans[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                
                j++;
                i--;
            }
            
            if (i >= 0) {
                while (head and i >= 0 and ans[i][j] == -1) {
                    ans[i][j] = head->val;
                    head = head->next;
                    i--;
                }

                i++;
                j++;
            }

            n--;
            m++;
        }

        return ans;
    }
};