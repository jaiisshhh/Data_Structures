#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this -> next = NULL;
        this -> prev = NULL;
    }

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while( temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLen(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else if(pos == 1){
        insertAtHead(head, tail, data);
    }
    else if(pos == getLen(head) + 1){
        insertAtTail(head, tail, data);
    }
    else{
        Node* newNode = new Node(data);
        Node* prevNode = head;
        Node* currNode = head -> next;
        for(int i=1; i<pos - 1; i++){
            prevNode = currNode;
            currNode = currNode -> next;
        }
        prevNode -> next = newNode;
        newNode -> prev = prevNode;
        newNode -> next = currNode;
        currNode -> prev = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        cout << "Cannot Delete, LL is empty" << endl;
        return;
    }
    else if(pos <= 0 || pos > getLen(head)){
        cout << "Invalid Positon" << endl;
        return;
    }
    else if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
    }
    else if(pos == getLen(head)){
        Node* prevNode = tail -> prev;
        prevNode -> next = NULL;
        tail -> prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        Node* prevNode = head;
        Node* currNode = head -> next;
        for(int i=1; i<pos-1; i++){
            prevNode = currNode;
            currNode = currNode -> next;
        }
        Node* nextNode = currNode -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        currNode -> next = NULL; 
        currNode -> prev = NULL;
        delete currNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL; 
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);
    //insertAtPos(head, tail, 55, 6);
    cout << getLen(head) << endl;

    print(head);

    deleteNode(head, tail, 3);
    print(head);
    cout << getLen(head) << endl;

}