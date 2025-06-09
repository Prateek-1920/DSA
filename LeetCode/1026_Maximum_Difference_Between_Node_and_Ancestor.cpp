/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root,int minval, int maxval, int &maxdif){
        if(root==NULL)return ;
        if(root->val>maxval){maxval=root->val;}
        if(root->val<minval){minval=root->val;}
        int diff = max(abs(root->val-minval),abs(root->val-maxval));
        if(diff>maxdif){maxdif=diff;}
        dfs(root->left,minval,maxval,maxdif);
        dfs(root->right,minval,maxval,maxdif);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxdif = 0;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        dfs(root,minval,maxval,maxdif);
        return maxdif;
    }
};