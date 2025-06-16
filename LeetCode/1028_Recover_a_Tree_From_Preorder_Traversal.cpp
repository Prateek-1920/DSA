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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> depth_val;
        int i = 0;

        while(i < traversal.length()) {
            int depth = 0;
            while(i < traversal.length() && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            string num = "";
            while(i < traversal.length() && isdigit(traversal[i])) {
                num += traversal[i];
                i++;
            }
            
            depth_val.push_back({depth, stoi(num)});
        }


        stack<TreeNode*> nodestack;
        for(auto &it : depth_val){
            while(nodestack.size()>it.first){
                nodestack.pop();
            }
            TreeNode* node = new TreeNode(it.second);
            if(!nodestack.empty()){
                nodestack.top()->left==NULL?nodestack.top()->left = node : nodestack.top()->right= node;   
            }

            nodestack.push(node);
        }

        TreeNode* root;
        while(!nodestack.empty()){
            root = nodestack.top();
            nodestack.pop();
        }
        return root;

    }
};