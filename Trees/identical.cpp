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

bool identical(Treenode* p, Treenode* q){
    if(p==NULL && q==NULL)return true;
    if(p==NULL || q==NULL)return false;
    return (p->val==q->val) && identical(p->left,q->left) && identical(p->right, q->right);
}

int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->right->left= new Treenode(5);

    Treenode* root2 = new Treenode(1);
    root2->left = new Treenode(2);
    root2->right= new Treenode(3);
    root2->left->left= new Treenode(9);
    root2->right->left= new Treenode(5);

    bool b = identical(root,root2);
    cout<< (b==true?"Trees are identical" :"Trees are NOT identical");
    return 0;   
}