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
    TreeNode* build(vector<int>& nums, int start, int end){
        if(start>end)return NULL;
        int maxele=INT_MIN,maxind=-1;
        for(int i=start;i<=end;i++){
            if(nums[i]>maxele){
                maxele=nums[i];
                maxind = i;
            }
        }
        TreeNode* root = new TreeNode(maxele);
        root->left = build(nums,start,maxind-1);
        root->right = build(nums,maxind+1,end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};