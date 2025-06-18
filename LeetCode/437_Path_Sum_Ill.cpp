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
    long long dfs(TreeNode* node, long long target){
        if(node==NULL)return 0;
        long long count = 0;
        if(node->val==target)count++;
        count += dfs(node->left,target-node->val);
        count += dfs(node->right,target-node->val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        long long pathroot = dfs(root,targetSum);
        long long pathleft = pathSum(root->left,targetSum);
        long long pathright = pathSum(root->right,targetSum);
        
        return pathroot + pathleft + pathright;
    }
};