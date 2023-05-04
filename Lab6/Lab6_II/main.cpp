#include <iostream>
#include<chrono>
using namespace std;
///////////////implement stack using linked list/////////
struct node{
    int data;
    struct node *next;
};

struct node* head =NULL;
void push(int data){
    struct node* tempNode=(struct node*)malloc(sizeof(struct node));
    tempNode->data=data;
    tempNode->next=NULL;
    if(head==NULL){
        head=tempNode;return;
    }
    tempNode->next=head;
    head=tempNode;
}
int pop(){
    if (head==NULL){cout << "Stack underflow";exit(1);}
    int data=head->data;
    head=head->next;
    return data;
}
void display(){
    if(head==NULL){
        cout<<"Stack is empty"<<endl;
        exit(1);
    }
    node *tempNode=head;
    cout<<"[";
    while(tempNode->next!=NULL){
        cout<<tempNode->data<<",";
        tempNode=tempNode->next;
    }
    cout<<"\b]\n";
}
int main() {
    //////////////////////////////////////////

    cout<<"Stacks implement using LinkedList"<<endl;

    auto begin =chrono::high_resolution_clock::now();
    for(int i=0;i<10;i++){
        push(rand()%100); //push 10 items to the stack
    }
    display();
//    for(int i=0;i<5;i++){cout<<pop()<<endl;}
    for(int i=0;i<5;i++){ //pop 5 items from stack
        pop();
    }
    display();
    for(int i=0;i<4;i++){push(rand()%100);}  //push 4 items to the stack
    display();
    auto end =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
    return 0;
}

