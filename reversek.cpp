#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node * linkChain(Node *prev,int data)
{
    Node* node = new Node;
    node->data  = data;
    node->next = NULL;
    if(prev==NULL){
        return(node);
    }
    prev->next = node;
    return(node);
}

Node** reverseList(Node *root, int k, int size){
    // cout << root;
    Node *start = root;
    Node *temp=NULL,*prev=NULL;
    int length = size/k + 1;
    Node *roots[length];
    int i=0;
    // cout << root << start;
    int iterator = 1;
    while(start != NULL){
       if(iterator > k){
           iterator = 1;
       }
    //    cout << start <<"  ||  "<< prev <<"  ||  " << temp << "\t\t\t";
    //    start = start->next;
       while(iterator <= k){
        //  cout << "Iteration: "<< iterator << k <<  start <<"  ||  "<< prev <<"  ||  " << temp << "\t\t\t";
         temp = start->next;
         start->next = prev;
         prev = start;
         start = temp;
         iterator++;
        //  cout << start<<"  ||  " << prev<<"  ||  " << temp << "\n";  
       }
       roots[i] = prev;
       temp = prev = NULL;
       i++;
   }
    Node **p = roots;
    return(p);
    // cout << roots[0]<<"  ||  " << roots[1]<<"  ||  " << roots[2] << "\n";
   
}

int main(){

    Node *root = linkChain(NULL,1);
    Node *next = linkChain(root,2);
          next = linkChain(next,3);
          next = linkChain(next,4);
          next = linkChain(next,5);
          next = linkChain(next,6);
    // while(root!=NULL){
    //     cout << root << "\t" <<root->data << "\n";
    //     root = root->next;
    // }
    Node **p = reverseList(root,3,6);
    Node *root2;
    cout << *p<< " || "<< (*p)->data << " || "<< (*p)->next << " || "<< (*p)->next->data << " || "<< (*p)->next->next << " || "<< (*p)->next->next->data<< " || "<< (*p)->next->next->next<<"\n";
    p++;
    cout << *p << " || "<< (*p)->data;
    // for(int i=0;i<2;i++){
    //     root2 = *p;
    //     cout << root2 << root2->data;
    //     // while(root2 != NULL){
    //     //     cout << root2->data;
    //     //     root2= root2->next;
    //     // }
    //     p++;
    // }
    return 0;
}
