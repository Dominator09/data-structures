#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
    Node *next;
    int data;
};


struct Stack {
    int* top;
    
    int* initialise(int size){
       top = (int *)calloc(size,sizeof(int));
       return top;
    }
    int* push(int x){
        top++;
        *top = x;
        return top;
    }

    int* pop(){
        return --top;
    }

    int* getTop(){
        return top;
    }
};

struct Node* linkChain(int length){
    struct Node *root= NULL,*next= NULL,*current= NULL;
    root = next = (struct Node *)malloc(sizeof(struct Node));
    root->data = 0;
    root->next = NULL;
    for(int i=1;i<length;i++){
       current = (struct Node *)malloc(sizeof(struct Node));
       current->data = i;
       next->next = current;
       next = current;
    }
    // cout << root << root->next << root->data;
    return root;
}

void printChain(struct Node* iterator){
    // cout << iterator-> next << iterator -> data;
    int x[10] = {0,1,2,3,4,5,6,7,8,9};
    int *t = x;
    while(iterator != NULL){
        cout << iterator->data << " " << iterator << "\t" << *t << " "<< t <<"\n";
        iterator = iterator-> next;
        t++;
    }
    
}
int main()
{   
    // struct Node *chain1,*chain2;
    // chain1 = linkChain(10);
    // printChain(chain1);

    struct Stack stack;
    stack.initialise(10);
    
    for(int t=0;t<10;t++){
        stack.push(t);
        cout << *(stack.top);
    }
    
    return 0;
}