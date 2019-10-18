#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}

int check(int dist);
void put(int,int);

void printTopView(Node *root,int distance){
    if(root==NULL){
        return;
    }
    if(root && !check(distance)){
       printf("%d",root->data);
       put(root->data,distance);
    }
    if(root->left !=NULL){
        printTopView(root->left,distance-1);
    }
    if(root->right != NULL){
        printTopView(root->right,distance +1);
    } 
}

int main(){
    Node *a = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
    printTopView(a,0);
    return 0;
}