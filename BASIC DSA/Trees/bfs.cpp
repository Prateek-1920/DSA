// ALSO CALLED LEVEL ORDER TRAVERSAL

#include<iostream>
#include<queue>
using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;

    Treenode(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void bfs(Treenode* root){
    if(root==NULL)return ;
    queue<Treenode*> q;
    q.push(root);

    while(!q.empty()){
        Treenode* curr = q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left!=NULL)q.push(curr->left);
        if(curr->right!=NULL)q.push(curr->right);
    }
}


int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->right->left= new Treenode(5);

    cout<<"BFS Traversal: ";
    bfs(root);
    return 0;   
}