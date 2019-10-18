#include<stdlib.h>
#include<stdio.h>


struct Node {
    int data;
    Node *left,*right;
};

int findklargest(Node *,int);

Node* newNode(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left=node->right = NULL;
    return(node);
}

void visit(Node* a,int *pos){
     if(*pos == 1){
         printf("%dth smallest element is : %d",*pos,a->data);
     }
     *pos = (*pos) - 1;
}

int findklargest(Node *a,int *pos){
    if(a == NULL){
       return 0;
    }
    findklargest(a->left,pos);
    visit(a,pos);
    findklargest(a->right,pos);

}

int main(){
    int k=6;
    Node *a =  newNode(9);
    a->left = newNode(7);
    a->right = newNode(12);
    a->left->left = newNode(6);
    a->left->right = newNode(8);
    a->right->left = newNode(11);
    a->right->left->left = newNode(10);
    findklargest(a,&k);
    return 0;
}





