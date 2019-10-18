#include<stdio.h>
#include<stdlib.h>

using namespace std;


struct Node {
   int data;
   Node *left,*right;
};


void inOrder(Node *root){
   if(root==NULL){
       return;
   }
   inOrder(root->left);
   printf("%d",root->data);
   inOrder(root->right);
}

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return(temp);
}

int printPath(Node *root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data == data){
        printf("%d",root->data);
        return true;
    }
    if(printPath(root->left,data)){
        printf("%d",root->data);
        return true;
    };
    if(printPath(root->right,data)){
        printf("%d",root->data);
        return true;
    }
    return false;
}

int main(){
    
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->right = newNode(8);
    if(!printPath(root,9)){
       printf("No Path Found");
    };
    
    return 0;
}