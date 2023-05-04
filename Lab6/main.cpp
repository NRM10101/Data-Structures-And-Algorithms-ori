///////////////////Lab 05//////////////////
#include <iostream>
#include <chrono>
using namespace std;

////////implement stack using array////////////
class Stack{   //class stack
    int stack_arr[500];//defualt create a 500 size of stacck
    int top=-1;//top=-1 indicates th stack is empty
public:
    int pop(){
        if(top==-1){
            cout<<"Stack underflow";
            exit(1);
        }
        top--;
        return stack_arr[top+1];
    }
    void display(){
        cout<<"[";
        for(int i=0;i<=top;i++){
            cout<<stack_arr[i]<<",";
        }
        cout<<"\b]\n";
    }

public:
    void push(int data){
        if(top==500-1) {
            cout << "Stack overflow";
            return;
        }
        top++;
        stack_arr[top]=data;
    }
};
int main() {
    //////////////////////////////////////////

    cout<<"Stacks implement using arrays"<<endl;
    Stack stack;   //create a stack

    auto begin =chrono::high_resolution_clock::now();
    for(int i=0;i<10;i++){
        stack.push(rand()%100); //push 10 items to the satck
    }
    stack.display();
    //for(int i=0;i<5;i++){cout<<pop()<<endl;}
    for(int i=0;i<5;i++){ //pop 5 items from stack
        stack.pop();
    }
    stack.display();
    for(int i=0;i<4;i++){stack.push(rand()%100);}  //push 4 items to the stack
    stack.display();
    auto end =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
    return 0;
}
