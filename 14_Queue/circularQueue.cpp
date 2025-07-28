#include <iostream>
using namespace std;

class circularQueue{
    public : 
        int* arr;
        int size;
        int front;
        int rear;
        circularQueue(int size){
            arr = new int[size];
            this -> size = size;
            front = -1;
            rear = -1;
        }

        void push(int val){
            //Overflow
            if((front == 0 && rear == size - 1) || front - 1 == rear){ // Galti
                cout << "Overflow" << endl;
                return;
            }
            //Empty
            else if(front == -1 && rear == -1){ // Dhiyan rakhna single element
                front++;
                rear++;
                arr[rear] = val;
            }
            //Circular Nature
            else if(rear == size - 1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            //Normal
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            //Underflow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            //Empty Case
            else if (rear == front){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            //Circular Nature
            else if(front == size -1){
                arr[front] = -1;
                front = 0; 
            }
            //Normal 
            else{
                arr[front] = -1;
                front++;
            }
        }
        void print(){
            cout << "Printing Queue : ";
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    circularQueue q(5);
    q.print();
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.push(60);
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(60);
    q.print();
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
}