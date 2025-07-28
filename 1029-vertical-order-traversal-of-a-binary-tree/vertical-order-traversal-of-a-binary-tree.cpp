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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            TreeNode* node = vec.first;
            int x = vec.second.first; 
            int y = vec.second.second;
            mp[x][y].insert(node->val); 
            if(node->left!=NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto &it : mp){
            vector<int> res;
            for(auto &j :it.second){
                res.insert(res.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};