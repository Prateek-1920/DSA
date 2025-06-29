#include<iostream>
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

int leafnodes(Treenode* root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 1;
    return leafnodes(root->left) + leafnodes(root->right);
}

int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->right->left= new Treenode(5);

    int n = leafnodes(root);
    cout<<"Leaf nodes in the tree is : "<<n;   
}