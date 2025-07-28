#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public: 
    int *arr;
    int size;
    int top;
    Stack(int size){
        arr = new int[size];
        this -> size = size;
        this -> top = -1;
    }
    void push(int data){
        if(top == size - 1){
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        else{
            top--;
        }
    }
    bool Empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    int getTop(){
        if(top == -1){
            cout << "Stack is Empty" << endl;
        }
        else{
            return arr[top];
        }
    }
    int getSize(){
        return top + 1;
    }
    void print(){
        cout << "Top : " << top << endl;
        cout << "Top Element : " << getTop() << endl;
        cout << "Stack : ";
        for(int i=0; i<getSize(); i++){
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};

int main(){
    // Static Creation
    Stack st(8);
    st.push(10);
    st.print();
    st.push(20);
    st.print();
    st.push(30);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();

}