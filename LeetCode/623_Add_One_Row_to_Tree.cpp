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
    void insert(TreeNode* root, int val, int depth, int currheight){
        if(root==NULL)return ;
        if(currheight==depth-1){
            TreeNode* leftnode = new TreeNode(val);
            TreeNode* rightnode = new TreeNode(val);

            leftnode->left = root->left;
            rightnode->right = root->right;

            root->left = leftnode;
            root->right = rightnode;
        }
        else{
            insert(root->left,val,depth,currheight+1);
            insert(root->right,val,depth,currheight+1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return new TreeNode(val,root,nullptr);
        }
        insert(root,val,depth,1);
        return root;

    }
};