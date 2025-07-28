#include<iostream>
using namespace std;

class deque{
    public : 
        int* arr;
        int size;
        int front;
        int rear;
        deque(int size){
            arr = new int[size];
            this -> size = size;
            front = -1;
            rear = -1;
        }

        void push_front(int val){
            //Overflow
            if((front == 0 && rear == size - 1) || front - 1 == rear){ // Galti
                cout << "Overflow" << endl;
                return;
            }
            //Empty
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }
            // Circular Nature
            else if(front == 0 && rear != size - 1){
                front == size - 1;
                arr[front] = val; 
            }
            //Normal
            else{
                front--;
                arr[front] = val; 
            }
        }
        void push_back(int val){
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
        void pop_front(){
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
        void pop_back(){
            // Underflow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            // Empty
            else if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            // Circular Nature
            else if(rear == 0){
                arr[rear] = -1;
                rear = size - 1;
            }
            // Normal
            else{
                arr[rear] = -1;
                rear--;
            }
        }
};

int main(){
    
}