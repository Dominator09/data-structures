#include<stdio.h>
#include<iostream>

using namespace std;

class Node{
    private:

        Node *next;
        int data;

    public:
        
        Node(int i){
          data = i;
        }
        int getData(){
            return data;
        }

        void setNext(Node *n){
            this->next = n;
        }

        Node * getNext(){
            return this-> next;
        }
        
        void setData(int d){
            data = d;
        }

        void printData(){
            cout << data;
        }
};

int main()
{   Node *root,*next,*node;
    next = root = new Node(0);
    
    for(int i=1;i<10;i++){
        node = new Node(i);
        next->setNext(node);
        next = node;
    }
    Node *iterator = root;
    for(int i=1;i<10;i++){
       iterator->printData();
       iterator = root->getNext();
    }
    return 0;
}