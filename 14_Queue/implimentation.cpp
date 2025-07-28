// QUEUE USING ARRAY

#include<iostream>
using namespace std;

class Queue{
    public: 
        int *arr;
        int size;
        int front;
        int rear;
        Queue(int size){
            arr = new int[size];
            this -> size = size;
            this -> front = -1;
            this -> rear = -1;
        }
         
        void push(int val){
            if(rear == size - 1){
                cout << "Queue Overflow" << endl;
                return;
            }
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            if(front == -1 && rear == -1){
                cout << "Queue Underflow" << endl;
                return;
            }
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else{
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }
            else{
                return rear - front + 1;
            }
        }

        int getFront(){
            if(front == -1){
                cout << "No element in Queue" << endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        void print(){
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    Queue q(5);
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
    cout << "Size of queue : " << q.getSize() << endl;
    q.pop();
    q.print();
}