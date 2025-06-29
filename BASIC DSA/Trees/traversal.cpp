// ALL OF THESE CAN BE CONSIDERED DFS TRAVERSAL 


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

void inorder(Treenode* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Treenode* root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Treenode* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}


int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->right->left= new Treenode(5);

    cout<<"Inorder: ";
    inorder(root);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"Postorder: ";
    postorder(root);

}