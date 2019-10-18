#include<stdio.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
};

Node* newNode(int data)
{
    Node *node = new Node;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return(node); 
}

void preOrder(Node *root){
    Node *start = root;
    if(start==NULL){
        return;
    }
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int sum(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int sum1 = sum(root->left) + sum(root->right);
        root->data =  sum1 > 0 ? sum1:root->data;
        return root->data;
    }
    };

int main()
{
    Node *a =  newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left = newNode(4);
    a->left->right = newNode(5);
    a->right->left = newNode(6);
    a->right->right = newNode(7);
    preOrder(a);
    sum(a);
    printf("\n\n");
    preOrder(a);
    return 0;
}