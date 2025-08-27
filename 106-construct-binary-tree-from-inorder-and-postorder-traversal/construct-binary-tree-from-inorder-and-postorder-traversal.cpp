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
    TreeNode* helper(vector<int>&postorder,vector<int>&inorder,unordered_map<int,int>&inmap, int& postindex, int instart, int inend){
        if(instart>inend)return NULL;

        int rootval = postorder[postindex];
        postindex--;
        TreeNode* root = new TreeNode(rootval);

        int inindex = inmap[rootval];

        root->right = helper(postorder,inorder,inmap,postindex,inindex+1,inend);
        root->left = helper(postorder,inorder,inmap,postindex,instart,inindex-1);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        int postindex = postorder.size()-1;
        return helper(postorder,inorder,mp,postindex,0,inorder.size()-1);
    }
};