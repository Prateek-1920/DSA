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
    void dfs(TreeNode* root,vector<int> path, vector<vector<int>> &result,int target){
        if(root==NULL)return ;

        path.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(accumulate(path.begin(),path.end(),0)==target){
                result.push_back(path);
                return;
            }
        }
        dfs(root->left,path,result,target);
        dfs(root->right,path,result,target);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        dfs(root,{},answer,targetSum);
        return answer;

    }
};