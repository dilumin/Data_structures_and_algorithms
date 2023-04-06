
#include <iostream>
#include <sys/time.h>
#include <ctime>

using namespace std;
//stack class
class stack_array {
public:
    int size;
    int* arr;
    int pointer = -1;

    stack_array(int size_1) {
        size = size_1;
        arr = new int[size]{0};
    }
    //adding values to the stack
    void push(int n) {
        if (pointer + 1 < size) {
            arr[pointer + 1] = n;
            pointer++;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }
    //removing elemets from the stack
    int pop() {
        if (pointer >= 0) {
            pointer--;
            return arr[pointer + 1];
        } else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }
    //checking if full
    bool isFull(){
        if (size -1 == pointer){
            return true;
        }else{return false;}
    }
    //checking if empty
    bool isEmpty(){
        if(pointer == -1){
            return true;
        }else{return false;}
    }
    //top value return
    int StackTop(){
        return arr[0];
    }
    //dispaying the stack
    void Display(){
    for (int i = pointer; i >=0; i--){
        cout << arr[i] << " ";
    }
    cout << endl;
}
};

int main() {
    
    struct timeval start,end;
    gettimeofday(&start,NULL);
    ios_base::sync_with_stdio(false);

    stack_array stack1(10);
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
    cout << "Time for normal stack- " << (end.tv_sec-start.tv_sec)*1000000  + (end.tv_usec-start.tv_usec) << endl;
    return 0;
}
