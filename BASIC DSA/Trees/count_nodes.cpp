#include<iostream>
using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;

    Treenode(int value){
        val = value;
        left = nullptr;
        right= nullptr;
    }
};

int countnodes(Treenode* root){
    if(root==NULL)return 0;
    return 1+countnodes(root->left) + countnodes(root->right);
}


int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->right->left= new Treenode(5);

    int n = countnodes(root);
    cout<<"Nodes in the tree is : "<<n;   
}