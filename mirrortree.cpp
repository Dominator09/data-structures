#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};


int findMirror(Node* a,Node* b)
{      
     cout<< a->data;
     cout<<b->data; 
        if(a==NULL && b==NULL)
            return true;
    
        if (a==NULL || b==NULL)
            return false;
    
        return a->data == b->data &&
         findMirror(a->left, b->right) &&
         findMirror(a->right, b->left);
}

Node* newNode(int data)
{
    Node *node = new Node;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return(node); 
}

int main()
{
    Node *a =  newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
  
    Node *b = newNode(1);
    b->left = newNode(3);
    b->right = newNode(2);
   
    findMirror(a,b)? cout << "Yes" : cout << "No";
    // cout << "\n\n\n"<< x;
    return 0;
}