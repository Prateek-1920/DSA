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
    bool iseven(int n){
        if(n%2==0){
            return true;
        }
        return false;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*> q;
        q.push(root);
        int levelidx = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }

            if (iseven(levelidx)) {
                if (iseven(level[0])) return false;
                for (int i = 1; i < level.size(); i++) {
                    if (iseven(level[i]) || level[i] <= level[i - 1]) return false;
                }
            }
            else {
                if (!iseven(level[0])) return false;
                for (int i = 1; i < level.size(); i++) {
                    if (!iseven(level[i]) || level[i] >= level[i - 1]) return false;
                }
            }

            
            levelidx++;
        }
        return true;
    }
};