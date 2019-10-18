#include<bits/stdc++.h>
#define RED 1
#define BLACK 0
using namespace std;

struct Node {
    int data;
    int color;
    Node *left,*right;
};


Node* newNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->color = 1;
    node->left = node->right = NULL;
    return node;
}

int color(Node *x){
    return x->color;
};

Node* parent(Node *x,Node *pivot){
    Node *traverser = pivot;
    if(x==NULL){
        return NULL;
    }
    if(x->data == traverser->data){
        return NULL;
    }
    if(traverser->left && traverser->left->data == x->data ||
    traverser->right && traverser->right->data == x->data){
        return traverser;
    }
    if(traverser->data > x->data){
        return parent(x,traverser->left);
    }
    else{
        return parent(x,traverser->right);
    }
    
};
Node* uncle(Node *x,Node *pivot){
    Node *a = parent(x,pivot);
    Node *grandAncestor = parent(parent(x,pivot),pivot);
    if(a && grandAncestor && grandAncestor->left == a){
        return grandAncestor->right;
    }
    else if(a && grandAncestor){
        return grandAncestor->left; 
    }
    else{
        return NULL;
    }
};


Node* recolor(Node *x,Node *pivot,int color){
      (parent(x,pivot))->color = BLACK;
      (uncle(x,pivot))->color = BLACK;
      Node *grand = parent(parent(x,pivot),pivot);
      grand->color = RED;
      return grand; 
};



void insertNode(Node *root,int data,Node *pivot ){
     if(root==NULL){
        root= newNode(data);
        if(color(uncle(root,pivot)) == RED){
            recolor(root,pivot,RED);
        }
        else if(color(uncle(root,pivot)) == BLACK){
            recolor(root,pivot,BLACK);
        }   
        return;
     }
     else if(data <= root->data){
          insertNode(root->left,data,pivot);   
     }
     else{
          insertNode(root->right,data,pivot);   
     }     
}

int main(){
 
    Node *root;
    root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(10);
    root->right->right->right = newNode(12);
    // Node *b = root->left;
    // Node *b = uncle(root->left,root);
    // if(b == NULL){
    //     printf("THIS");
    // }
    // else{
    //     printf("THAT %d",b->data);
    // }
    cout << uncle(root->left,root);
    // printf("PARENT IS :%d",(parent(root->right->right->right,root))->data);

    
    return 0;
}