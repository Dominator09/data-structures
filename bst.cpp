#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *left,*right;
};

int traverse(Node*,Node*);

Node* newNode(int data){
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

void preOrder(Node *root){
    Node *start = root;
    if(start==NULL){
        return;
    }
    printf("%d\n",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void addTreeElement(Node *root,int data){
    Node *element = newNode(data);
    traverse(root,element);
}

int traverse(Node *root,Node *element){
    if(root==NULL){
        root = element;
        return 0;
    }
    if(root->data > element->data){
        if(root->left==NULL){
           root->left = element;
           return 0;
        }
        else{
            traverse(root->left,element);
        }
    }
    else{
        if(root->right==NULL){
           root->right = element;
           return 0;
        }
        else{
            traverse(root->right,element);
        }
    }
}

int main(){
    int dataset[] = {20,10,56,67,45,12,23,54};
    Node *root = newNode(dataset[0]);
    for(int i=1;i<8;i++){
        addTreeElement(root,dataset[i]);
    }
    
    preOrder(root);
    return 0;
}

