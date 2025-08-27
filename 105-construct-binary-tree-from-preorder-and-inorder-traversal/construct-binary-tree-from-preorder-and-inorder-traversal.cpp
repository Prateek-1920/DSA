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
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&inmap, int& preindex, int instart, int inend){
        if(instart>inend)return NULL;

        int rootval = preorder[preindex];
        preindex++;
        TreeNode* root = new TreeNode(rootval);

        int inindex = inmap[rootval];

        root->left = helper(preorder,inorder,inmap,preindex,instart,inindex-1);
        root->right = helper(preorder,inorder,inmap,preindex,inindex+1,inend);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        int preindex = 0;
        return helper(preorder,inorder,mp,preindex,0,preorder.size()-1);
    }
};