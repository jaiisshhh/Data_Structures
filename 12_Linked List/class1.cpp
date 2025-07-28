#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){this->next = NULL;} // Default Constructor
        Node(int data){this->data = data; this->next = NULL;} // Parameterized Constructor
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
} 

int getLength(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
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
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos) {
    // Handle invalid position
    if (pos < 0) {
        return;
    }
    // Handle insertion at the head
    if (pos == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    // Check if the list is empty
    if (head == nullptr) {
        // If the position is not zero, insertion is invalid
        if (pos > 0) {
            return;
        }
        // Insert at head for an empty list
        insertAtHead(head, tail, data);
        return;
    }
    // Handle insertion at or beyond the tail
    if (pos >= getLength(head)) {
        insertAtTail(head, tail, data);
        return;
    }
    // Handle insertion at a valid middle position
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == nullptr) { 
            break;
        }
        temp = temp->next;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void createTail(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    tail = temp;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        cout << "LL is empty, cannot delete" << endl;
        return;
    }
    if(pos <= 0 || pos > getLength(head)){
        cout << "Invalid position" << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    if(pos == getLength(head)){
        Node* prev = head;
        while(prev -> next != tail){
            prev = prev -> next;
        }
        prev -> next = NULL;
        delete tail;
        tail = prev;
        return;
    }
    else{
        Node* prev = head;
        Node* curr = head->next;
        for(int i = 1; i < pos - 1; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr -> next = NULL;
        delete curr;    
    }
}

int main(){
    // Creation of Linked List

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    deleteNode(head, tail, 3);
    printList(head);
}