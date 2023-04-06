#include <iostream>
#include <sys/time.h>

using namespace std;
//creating a node
struct Node{
    Node* next;
    int data;
};

class stack{
public:
    stack(){
        top = nullptr;
    }
    //to add data to the stack
    void push(int data){
        
        Node* temp = new Node();
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    //to remove elemets from stack
    int pop(){
        if (top == nullptr){
            cout << "Stack is empty" << endl;
            return -1; 
        }
        int a = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return a;
    }
    //check if empty
    bool isEmpty(){
        if (top == nullptr){
            return true;
        }
    }
    //top value of the stack
    int Stack_top(){
        return top->data;
    }
    // displaying the stack
    void Display(){
        Node *temp = top;
        while(temp->next!=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }cout << temp->data << endl;
    }


private:
    Node* top;     
};

int main(){

    struct timeval start,end;
    gettimeofday(&start,NULL);
    ios_base::sync_with_stdio(false);

    stack stack1;
    stack1.push(8);
    stack1.push(10);
    stack1.push(7);
    stack1.push(1);
    stack1.push(86);
    stack1.push(24);
    stack1.push(4);
    stack1.push(1);
    stack1.push(2);
    stack1.push(19);
    stack1.Display();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.Display();
    stack1.push(6);
    stack1.push(54);
    stack1.push(45);
    stack1.push(2);
    stack1.Display();

    gettimeofday(&end,NULL);
    cout << "For Linked list stack - " << (end.tv_sec-start.tv_sec)*1000000  + (end.tv_usec-start.tv_usec) << endl;

}


