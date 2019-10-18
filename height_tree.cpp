#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};


int max(int x, int y){
    return x > y?x : y;
}

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->right==NULL && root->left==NULL){
        return 1;
    }

    return 1 + max(height(root->left),height(root->right));
}