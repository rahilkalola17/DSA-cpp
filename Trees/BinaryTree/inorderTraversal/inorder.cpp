#include<bits/stdc++.h>
using namespace std;
#include"../BinaryTree.h"

void inorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    BinaryTreeNode<int>* root{TakeInputLevelWise()};
    print(root);
    inorder(root);
}