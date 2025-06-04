/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* ptr = head;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; 

        int diridx = 0;
        int row = 0;
        int col = 0;
        while(head!=nullptr){
            ans[row][col] = head->val;
            int nextrow = row + dir[diridx][0];
            int nextcol = col + dir[diridx][1];
            if(nextrow < 0 || nextrow >= m || nextcol < 0 || nextcol >= n || ans[nextrow][nextcol] != -1){
                diridx = (diridx+1)%4;
                nextrow = row + dir[diridx][0];
                nextcol = col + dir[diridx][1];
            }
            row = nextrow;
            col = nextcol;
            head = head->next;
        }
        return ans;

    }
};