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
private:
    void height(TreeNode* root,int h, int &depth){
        if(root==NULL){
            return;
        }
        if(h>depth){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            depth = min(h,depth);
        }
        height(root->left,h+1,depth);
        height(root->right,h+1,depth);
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = INT_MAX;
        height(root,1,ans);
        return ans;
        
    }
};