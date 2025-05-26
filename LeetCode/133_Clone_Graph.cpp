/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* cloneutil(Node* node, unordered_map<Node*, Node*>&mp){
        Node* newnode = new Node(node->val);
        mp[node]=newnode;

        for(auto neighbour : node->neighbors){
            if(mp.find(neighbour)!=mp.end()){
                (newnode->neighbors).push_back(mp[neighbour]);
            }
            else{
                (newnode->neighbors).push_back(cloneutil(neighbour,mp));
            }
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL) return NULL;
        return cloneutil(node,mp);
    }
};
